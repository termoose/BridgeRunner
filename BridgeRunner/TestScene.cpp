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
    Ground->AddPoint( b2Vec2(0.0, 0.0) );
    Ground->AddPoint( b2Vec2( ScreenSize.width/32.0, 0 ) );
    Ground->Create();
    
    VehicleObject *Falling = new VehicleObject( b2Vec2( 0.0, -20.0 ) );
    Falling->Create();
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
    
}

void TestScene::tick( cocos2d::ccTime dt )
{
    World->DoStep();
}

void TestScene::ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event )
{
    
}
