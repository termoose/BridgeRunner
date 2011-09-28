//
//  InfiniteScene.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 9/27/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Physics.h"
#include "InfiniteScene.h"
#include "PhyGround.h"
#include "PhyWheel.h"
#include "BridgeSegment.h"

InfiniteScene::InfiniteScene() : Scene()
{    
    // Create ground
    PhyGround *Ground = new PhyGround();
    Ground->AddPoint( b2Vec2(0.0, 20.0) );
    Ground->AddPoint( b2Vec2(ScreenSize.width, 20.0) );
    World->AddPhyObj( Ground );

    PhyWheel *CircleTest = new PhyWheel( b2Vec2( ScreenSize.width / 2.4, 320.0 ) );
    World->AddPhyObj( CircleTest );
    
    // Bridge segment example
    b2Vec2 StartPos = b2Vec2( 220, 100 );
    b2Vec2 StopPos  = b2Vec2( 420, 190 );
    BridgeSegment *Segment = new BridgeSegment( StartPos, StopPos );
    World->AddPhyObj( Segment );
    
    // Second bridge segment
    b2Vec2 StartPos2 = b2Vec2( 100, 150 );
    b2Vec2 StopPos2  = b2Vec2( 210, 100 );
    BridgeSegment *Segment2 = new BridgeSegment( StartPos2, StopPos2 );
    World->AddPhyObj( Segment2 );
}

InfiniteScene::~InfiniteScene()
{
    
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
