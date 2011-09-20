//
//  Scene.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 9/6/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "Scene.h"

Scene::Scene()
{
    setIsTouchEnabled( true );
    setIsAccelerometerEnabled( false );

    schedule( schedule_selector( Scene::tick ) );

    CCSize ScreenSize = CCDirector::sharedDirector()->getWinSize();
    
    ClearTouches();
    
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
    
	glEnable(GL_TEXTURE_2D);
	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);	
}

void Scene::tick( cocos2d::ccTime dt )
{
    World->DoStep();
    
    // FIXME: Change force on Circle with respect to slope of current
    // bridge segment and weight of Circle (assuming g = 10 m/s^2).
    //CircleTest->AddTorque( -1.4 );
}

void Scene::ccTouchesBegin( cocos2d::CCSet *touches, cocos2d::CCEvent *event )
{
    CCSetIterator it;
    CCTouch *touch;
    
    for( it = touches->begin(); it != touches->end(); ++it )
    {
        touch = (CCTouch *)( *it );
        
        if( !touch )
            break;
        
        CCPoint location = touch->locationInView( touch->view() );
        location = CCDirector::sharedDirector()->convertToGL( location );
        
        Touches.first.push_back( b2Vec2( location.x, location.y ) );        
    }
}

void Scene::ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event )
{
	CCSetIterator it;
	CCTouch *touch;
    
	for( it = touches->begin(); it != touches->end(); ++it)
	{
		touch = (CCTouch *)( *it );
        
		if( !touch )
			break;
        
        CCPoint location = touch->locationInView( touch->view() );

		location = CCDirector::sharedDirector()->convertToGL( location );
        
        Touches.second.push_back( b2Vec2( location.x, location.y ) );
	}
}

void Scene::ClearTouches()
{
    Touches.first.clear();
    Touches.second.clear();
}

CCScene *Scene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new Scene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}