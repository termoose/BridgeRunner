//
//  TestScene.cpp
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "SimpleAudioEngine.h"
#include "TestScene.h"
#include "PhyGround.h"
#include "VehicleObject.h"
#include "BridgeSegment.h"
#include "PhyWheel.h"
#include "PhyJoint.h"

using namespace cocos2d;
using namespace CocosDenshion;

TestScene::TestScene()
{
    setIsTouchEnabled( true );
    setIsAccelerometerEnabled( false );
    
    CCSize ScreenSize = CCDirector::sharedDirector()->getWinSize();
    
    World = new Physics();
    
    schedule( schedule_selector( TestScene::tick ) );
    
    // Create ground
    PhyGround *Ground = new PhyGround();
    Ground->AddPoint( b2Vec2(0.0, 20.0) );
    Ground->AddPoint( b2Vec2(ScreenSize.width, 20.0) );
    World->AddPhyObj( Ground );
    
    // Falling vehicle
    VehicleObject *Falling = new VehicleObject( b2Vec2( ScreenSize.width / 2.1, ScreenSize.height / 1.0 ) );
    World->AddPhyObj( Falling );
    
    //PhyWheel *CircleTest = new PhyWheel( b2Vec2( ScreenSize.width / 2.0, ScreenSize.height / 2.0 ) );
    PhyWheel *CircleTest = new PhyWheel( b2Vec2( 0.0, -40.0 ) );
    Falling->AddChild( CircleTest );
    //World->AddPhyObj( CircleTest );
    
    PhyJoint *TestJoint = new PhyJoint( Falling, CircleTest, b2Vec2(0.0, 20.0), b2Vec2(0.0, 20.0) );
    
    // Bridge segment example
    /*
    b2Vec2 StartPos = b2Vec2( 120, 40 );
    b2Vec2 StopPos  = b2Vec2( 320, 190 );
    BridgeSegment *Segment = new BridgeSegment( StartPos, StopPos );
    World->AddPhyObj( Segment );
     */
    
}

TestScene::~TestScene()
{
    delete World;
    World = NULL;
}

CCScene *TestScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new TestScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}

void TestScene::draw()
{
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    glLineWidth( 2.0 );
    World->RenderAll();
    
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);	
}

void TestScene::tick( cocos2d::ccTime dt )
{
    World->DoStep();
}

void TestScene::ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event )
{
    
}
