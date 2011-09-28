//
//  Scene.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 9/6/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "BridgeSegment.h"
#include "Scene.h"

Scene::Scene()
{
    setIsTouchEnabled( true );
    setIsAccelerometerEnabled( false );
    
    ScreenSize = CCDirector::sharedDirector()->getWinSize();
    
    schedule( schedule_selector( Scene::tick ) );
    
    // Create the physics object
    World = new Physics();
}

Scene::~Scene()
{
    delete World;
    World = NULL;
}

void Scene::draw()
{
	glDisable(GL_TEXTURE_2D);
	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    
    glLineWidth( 2.0 );
    World->RenderAll();

    glColor4f( 1.0, 0.0, 0.0, 1.0 );
    ccDrawLine( BoxToCCVec( SegmentStart ), BoxToCCVec( SegmentStop ) );
    
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

b2Vec2 Scene::CCToBoxVec( cocos2d::CCPoint Point )
{
    return b2Vec2( Point.x, Point.y );
}

CCPoint Scene::BoxToCCVec( b2Vec2 Point )
{
    return CCPoint( Point.x, Point.y );
}

void Scene::tick( cocos2d::ccTime dt )
{
    World->DoStep();
}

void Scene::ccTouchesMoved( CCSet *touches, CCEvent *event )
{
    CCSetIterator it;
    CCTouch *touch;
    
    // FIXME: use anyObject() or begin()?
    touch = static_cast< CCTouch * >( touches->anyObject() );
    
    if( !touch )
        return;
    
    CCPoint location = touch->locationInView( touch->view() );
    location = CCDirector::sharedDirector()->convertToGL( location );

    SegmentStart = StartTouch;
    SegmentStop  = CCToBoxVec( location );
}

void Scene::ccTouchesBegan( cocos2d::CCSet *touches, cocos2d::CCEvent *event )
{
    CCSetIterator it;
    CCTouch *touch;

    // FIXME: for_each and lambda with C++11
    for( it = touches->begin(); it != touches->end(); ++it )
    {
        touch = static_cast< CCTouch * >( *it );
        
        if( !touch )
            break;
        
        CCPoint location = touch->locationInView( touch->view() );
        location = CCDirector::sharedDirector()->convertToGL( location );
        
        StartTouch = CCToBoxVec( location );
    }
}

void Scene::ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event )
{
	CCSetIterator it;
	CCTouch *touch;

    // FIXME: for_each and lambda with C++11
	for( it = touches->begin(); it != touches->end(); ++it )
	{
        touch = static_cast< CCTouch * >( *it );
        
		if( !touch )
			break;
        
        CCPoint location = touch->locationInView( touch->view() );
		location = CCDirector::sharedDirector()->convertToGL( location );
        
        if( b2Dot( SegmentStart - SegmentStop, SegmentStart - SegmentStop ) > 5.0 )
        {
            World->AddPhyObj( new BridgeSegment( SegmentStart, SegmentStop ) );
        }
        
	}
}

CCScene *Scene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new Scene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}