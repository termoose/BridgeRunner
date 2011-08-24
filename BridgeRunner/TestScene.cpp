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

PhyWheel *CircleTest;

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

    //PhyWheel *CircleTest = new PhyWheel( b2Vec2( ScreenSize.width / 2.0, ScreenSize.height / 2.0 ) );
    CircleTest = new PhyWheel( b2Vec2( ScreenSize.width / 1.3, 320.0 ) );
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

    CircleTest->AddTorque( -1.4 );
}

// Put these two touch functions into a higher class, then overwrite them as needed
void TestScene::ccTouchesBegin( cocos2d::CCSet *touches, cocos2d::CCEvent *event )
{
    
}

void TestScene::ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event )
{
	CCSetIterator it;
	CCTouch* touch;
    
	for( it = touches->begin(); it != touches->end(); ++it)
	{
		touch = (CCTouch*)(*it);
        
		if(!touch)
			break;
        
        CCPoint location = touch->locationInView(touch->view());
		
		location = CCDirector::sharedDirector()->convertToGL(location);
        
        if( location.x >= CircleTest->GetPosition().x * PTM_RATIO )
            CircleTest->AddTorque( -50.0 );
        else
            CircleTest->AddTorque( 50.0 );
	}
}
