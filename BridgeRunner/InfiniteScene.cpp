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

InfiniteGround *Ground;

InfiniteScene::InfiniteScene() : Scene(), Noise( 0.1, 1.0 )
{    
    CircleTest = new PhyWheel( b2Vec2( 10.0, 320.0 ) );
    World->AddPhyObj( CircleTest );

    for( float point = 0; point < ScreenSize.width; point += 5.0 )
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

}

void InfiniteScene::draw()
{
    if( Points.back().x < ScreenSize.width + 50.0 )
    {
        AddPoint( Points.back().x + 5.0 );
    }

    for( std::deque< GroundSegment * >::const_iterator it = GroundSegments.begin();
        it != GroundSegments.end(); ++it )
    {
        (*it)->GetBody()->SetTransform( (*it)->GetPosition() + b2Vec2(-1.0 / 32.0, 0.0 ), 0.0 );
    }
    
    Scene::draw();
    CircleTest->SetSpeed( 1.0 );
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
