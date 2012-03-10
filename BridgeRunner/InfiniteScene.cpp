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

InfiniteScene::InfiniteScene() : Scene(), Noise( 0.1, 1.0 ), LengthCounter( 0.0 ), GroundDelta( ScreenSize.width / 8.0 )
{    
    RollingCircle = new PhyWheel( b2Vec2( 10.0, 320.0 ) );
    World->AddPhyObj( RollingCircle );
    
    BallImage = CCSprite::spriteWithFile( "rolling_girl.png" );
    addChild( BallImage );

    //GroundSegment *InitialSegment = new GroundSegment( b2Vec2( 0.0, ScreenSize.height / 2.0 ),
    //                                                  b2Vec2( 200.0, ScreenSize.height / 2.0 ) );
    //World->AddPhyObj( InitialSegment );
    //InitialSegment->SetTextureID( GroundTexture->getName() );
    
    //  CCPoint( i, Noise.GetNoise( i / 30.0) * 80 + 100 ) 
    
    for( float i = 0.0; i < ScreenSize.width; i += GroundDelta )
    {
        GroundSegment *CurrentSegment = new GroundSegment( b2Vec2( i, 200.0 ),
                                                          b2Vec2( i + GroundDelta, 200.0 ) );
        
        CurrentSegment->SetTextureID( GroundTexture->getName() );
        
        World->AddPhyObj( CurrentSegment );
        GroundSegments.push_back( CurrentSegment );
    }
    
    //GroundSegments.push_back( InitialSegment );
}

InfiniteScene::~InfiniteScene()
{
}

void InfiniteScene::AddNewPoint( float NewPointOffset )
{
    b2Vec2 LastPoint = GroundSegments.back()->GetStopPoint();
    float NewPointPosition = LastPoint.x + NewPointOffset;

    b2Vec2 NewPointVector( NewPointPosition, Noise.GetNoise( LengthCounter / 100.0) * 80 + 100 );
    
    GroundSegment *NewSegment = new GroundSegment( GroundSegments.back()->GetStopPoint(), NewPointVector );
    
    // Set the ground texture
    NewSegment->SetTextureID( GroundTexture->getName() );
    
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
    float BallPosition = RollingCircle->GetPosition().x * PTM_RATIO;
    
    if( BallPosition < 100.0 )
    {
        RollingCircle->SetSpeed( 1.0 );
    }
    else if( BallPosition > ScreenSize.width )
    {
        RollingCircle->SetSpeed( 0.0 );
    }
    
    // Remove segments that scroll off screen
    if( GroundSegments.front()->GetStopPoint().x < 0.0 )
        RemovePoint();
    
    if( GroundSegments.back()->GetStopPoint().x < ScreenSize.width + GroundDelta )
    {
        AddNewPoint( GroundDelta );
    }
    
//    return;
//    //if( GroundSegments.back()->GetStopPoint().x < ScreenSize.width )
//        //AddPoint( Speed );
//    
//    if( GroundSegments.front()->GetStopPoint().x < 0.0 && GroundSegments.size() > 100 )
//        RemovePoint();
//    
//    // If we have more than three segments, we remove the oldest one
//    // Should be set in a file on disk, since it should be possible to purchase more segments
//    if( BridgeSegments.size() > 3 )
//    {
//        DeleteOldestSegment();
//    }
//    
//    float BallPosition = RollingCircle->GetPosition().x;
//    
//    // Breaking
//    if( BallPosition * PTM_RATIO > ScreenSize.width  )
//    {
//        RollingCircle->SetSpeed( 0.0 );
//    }
//    // Speeding up
//    else if( BallPosition * PTM_RATIO < 100.0 )
//    {
//        RollingCircle->SetSpeed( 1.0 );
//    }
    
    // Move all ground segments
    for( std::deque< GroundSegment * >::const_iterator it = GroundSegments.begin();
        it != GroundSegments.end(); ++it )
    {
        (*it)->SetTextureOffset();
        (*it)->SetLinearVelocity( b2Vec2( -Speed, 0.0 ) );
    }
    
    // Move all bridge segments
    for( std::deque< BridgeSegment * >::const_iterator it = BridgeSegments.begin();
        it != BridgeSegments.end(); ++it )
    {        
        (*it)->SetLinearVelocity( b2Vec2( -Speed, 0.0 ) );
    }

    LengthCounter += Speed;
    
    std::cout << "Speed: " << GroundSegments.back()->GetBody()->GetLinearVelocity().x << std::endl;
}

void InfiniteScene::draw()
{
    Scene::draw();
    
    BallImage->setPosition( CCPoint(RollingCircle->GetPosition().x * PTM_RATIO, RollingCircle->GetPosition().y * PTM_RATIO) );
    BallImage->setRotation( -CC_RADIANS_TO_DEGREES(RollingCircle->GetAngle()) );

    MoveScene( 8.0 );
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
