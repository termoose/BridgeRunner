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

PhyObj *ActiveObject;

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
    World->AddPhyObj( Ground );
    
    VehicleObject *Falling = new VehicleObject( b2Vec2( 0.0, 5.0 ) );
    World->AddPhyObj( Falling );
    ActiveObject = Falling;
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
    std::cout << "Pos: " << ActiveObject->GetPosition().y << " Angle: " << ActiveObject->GetAngle() << std::endl;
}

void TestScene::tick( cocos2d::ccTime dt )
{
    World->DoStep();
}

void TestScene::ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event )
{
    
}
