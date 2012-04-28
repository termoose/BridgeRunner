//
//  InfiniteScene.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 9/27/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "Physics.h"
#include "InfiniteScene.h"
#include "InfiniteGround.h"
#include "PerlinNoise.h"
#include "BridgeSegment.h"

InfiniteScene::InfiniteScene() : Scene(), Noise( 0.1, 1.0 ), LengthCounter( 0.0 ), GroundDelta( ScreenSize.width / 32.0 ), RemoveGroundProbability( 90.0 )
{    
    RollingCircle = new PhyWheel( b2Vec2( 10.0, 320.0 ) );
    World->AddPhyObj( RollingCircle );
    
    BallImage = CCSprite::spriteWithFile( "rolling_girl.png" );
    addChild( BallImage );

    // Fill ground with initial segments
    for( float i = 0; i < ScreenSize.width; i += GroundDelta )
    {
        b2Vec2 StartGroundPoint( i, Noise.GetNoise( i/30.0 )*80.0 + 100.0 );
        b2Vec2 EndGroundPoint( i + GroundDelta, Noise.GetNoise( (i + GroundDelta)/30.0 )*80.0 + 100.0 );
        
        GroundSegment *NewSegment = new GroundSegment( StartGroundPoint, EndGroundPoint );
        World->AddPhyObj( NewSegment );
        NewSegment->SetTextureID( GroundTexture->getName() );
        GroundSegments.push_back( NewSegment );
    }
}

InfiniteScene::~InfiniteScene()
{
}

void InfiniteScene::AddNewSegment( float Offset )
{
    auto LastSegment = GroundSegments.back();
    b2Vec2 LastPosition = LastSegment->GetStopPoint();
    
    float NewPosition = LastPosition.x + GroundDelta;
    
    b2Vec2 StopPosition( NewPosition, Noise.GetNoise(LengthCounter/30.0)*80 + 100.0 );
    //b2Vec2 StopPosition( NewPosition + GroundDelta, Noise.GetNoise( (NewPosition + GroundDelta)/30.0)*80.0 + 100.0 );
    
    GroundSegment *NewSegment = new GroundSegment( LastPosition, StopPosition );
    World->AddPhyObj( NewSegment );
    NewSegment->SetTextureID( GroundTexture->getName() );
    GroundSegments.push_back( NewSegment );
}

void InfiniteScene::RemoveSegment()
{
    World->RemPhyObj( GroundSegments.front()->GetObjectID() );
    GroundSegments.pop_front();
}

void InfiniteScene::MoveScene( float Speed )
{    
    if( GroundSegments.back()->GetStopPoint().x < ScreenSize.width - 20.0 )
        AddNewSegment( Speed );
    
    if( GroundSegments.front()->GetStartPoint().x < 10.0 )
        RemoveSegment();
    
    for( auto& Segment : GroundSegments )
    {
        Segment->SetLinearVelocity( b2Vec2(-Speed, 0.0) );
        Segment->SetTextureOffset( LengthCounter / PTM_RATIO / 2.0 );
    }
    
    LengthCounter += Speed;
}

void InfiniteScene::draw()
{
    Scene::draw();
    
    BallImage->setPosition( CCPoint(RollingCircle->GetPosition().x * PTM_RATIO, RollingCircle->GetPosition().y * PTM_RATIO) );
    BallImage->setRotation( -CC_RADIANS_TO_DEGREES(RollingCircle->GetAngle()) );

    MoveScene( 2.0 );
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
