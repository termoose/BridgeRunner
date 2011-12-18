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

InfiniteGround *Ground;

InfiniteScene::InfiniteScene() : Scene(), Noise( 0.1, 1.0 )
{    
    CircleTest = new PhyWheel( b2Vec2( 10.0, 320.0 ) );
    World->AddPhyObj( CircleTest );

    // Make the initial ground
    for( float point = 0; point < ScreenSize.width * 2.0; point += 5.0 )
    {
        AddPoint( point );
    }
}

InfiniteScene::~InfiniteScene()
{
    delete CircleTest;
    delete Ground;
}

void InfiniteScene::AddPoint( float NewPoint )
{
    Points.push_back( b2Vec2( NewPoint, Noise.GetNoise( NewPoint / 30.0) * 80 + 100 ) );
    
    if( Points.size() > 1 )
    {
        GroundSegment *NewSegment = new GroundSegment( Points[ Points.size() - 2 ], Points.back() );
        World->AddPhyObj( NewSegment );
        GroundSegments.push_back( NewSegment );
    }
}

void InfiniteScene::RemovePoint()
{
    std::cout << "Deleting!" << std::endl;
    Points.pop_front();
    delete GroundSegments.front();
    GroundSegments.pop_front();
}

void InfiniteScene::MoveGround( float Speed )
{
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
}

void InfiniteScene::draw()
{
    float GroundEdge = GroundSegments.back()->GetStopPoint().x;
    
    //std::cout << "Front X: " << GroundEdge << " ScreenEdge: " << ScreenSize.width << std::endl;

    if( GroundEdge < ScreenSize.width )
    {
        //std::cout << "Adding point: " << GroundEdge + 5.0 << std::endl;
        AddPoint( Points.back().x + 5.0 );
    }

    float BallPosition = CircleTest->GetPosition().x;

    //std::cout << "BallSpeed: " << BallSpeed << std::endl;
    if( BallPosition * PTM_RATIO > 50.0 )
    {
        //std::cout << "BREAK!" << std::endl;
        CircleTest->SetSpeed( 0.0 );
    }
    else
    {
        //std::cout << "SPEED!" << std::endl;
        CircleTest->SetSpeed( 2.0 );
    }

    Scene::draw();

    MoveGround( -1.0 );
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
