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

InfiniteScene::InfiniteScene() : Scene(), Noise( 0.1, 1.0 ), LengthCounter( 0.0 )
{    
    RollingCircle = new PhyWheel( b2Vec2( 10.0, 320.0 ) );
    World->AddPhyObj( RollingCircle );
    
    BallImage = CCSprite::spriteWithFile( "rolling_girl.png" );
    addChild( BallImage );

    GroundSegment *InitialSegment = new GroundSegment( b2Vec2( 0.0, ScreenSize.height / 2.0 ),
                                                      b2Vec2( 200.0, ScreenSize.height / 2.0 ) );
    World->AddPhyObj( InitialSegment );
    GroundSegments.push_back( InitialSegment );
}

InfiniteScene::~InfiniteScene()
{
}

void InfiniteScene::AddPoint( float NewPointOffset )
{
    b2Vec2 LastPoint = GroundSegments.back()->GetStopPoint();
    float NewPointPosition = LastPoint.x + NewPointOffset;

    b2Vec2 NewPointVector( NewPointPosition, Noise.GetNoise( (LengthCounter) / 30.0) * 80 + 100 );
    
    GroundSegment *NewSegment = new GroundSegment( GroundSegments.back()->GetStopPoint(), NewPointVector );
    World->AddPhyObj( NewSegment );
    GroundSegments.push_back( NewSegment );
}

void InfiniteScene::RemovePoint()
{
    World->RemPhyObj( GroundSegments.front()->GetObjectID() );
    GroundSegments.pop_front();
}

void InfiniteScene::MoveScene( float Speed )
{
    if( GroundSegments.back()->GetStopPoint().x < ScreenSize.width * 2.0 )
        AddPoint( -Speed );
    
    if( GroundSegments.front()->GetStopPoint().x < 0.0 && GroundSegments.size() > 100 )
        RemovePoint(); 
    
    float BallPosition = RollingCircle->GetPosition().x;
    
    // Breaking
    if( BallPosition * PTM_RATIO > ScreenSize.width * 1.0 )
    {
        RollingCircle->SetSpeed( 0.0 );
    }
    // Speeding up
    else if( BallPosition * PTM_RATIO < 100.0 )
    {
        RollingCircle->SetSpeed( 1.0 );
    }
    
    // Move all ground segments
    for( std::deque< GroundSegment * >::const_iterator it = GroundSegments.begin();
        it != GroundSegments.end(); ++it )
    {
        (*it)->SetLinearVelocity( b2Vec2( Speed, 0.0 ) );
    }
    
    // Move all bridge segments
    for( std::deque< BridgeSegment * >::const_iterator it = BridgeSegments.begin();
        it != BridgeSegments.end(); ++it )
    {        
        (*it)->SetLinearVelocity( b2Vec2( Speed, 0.0 ) );
    }

    LengthCounter += 2.0;
}

void InfiniteScene::draw()
{
    Scene::draw();
    
    BallImage->setPosition( CCPoint(RollingCircle->GetPosition().x * PTM_RATIO, RollingCircle->GetPosition().y * PTM_RATIO) );
    BallImage->setRotation( -CC_RADIANS_TO_DEGREES(RollingCircle->GetAngle()) );

    MoveScene( -8.0 );
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
