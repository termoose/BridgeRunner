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
#include "PhyGround.h"
#include "PhyWheel.h"
#include "BridgeSegment.h"
#include "PerlinNoise.h"

PerlinNoise *Noise;

InfiniteScene::InfiniteScene() : Scene()
{    
    // Create ground
    Noise = new PerlinNoise( 0.1, 1 );


    PhyWheel *CircleTest = new PhyWheel( b2Vec2( ScreenSize.width / 2.4, 320.0 ) );
    World->AddPhyObj( CircleTest );
    
    Ground = new PhyGround();
    
    for( float i = 0; i < 20.0; i += 5.0 )
    {
        b2Vec2 Point( i, Noise->GetNoise( i / 30.0 )*50 + ScreenSize.height / 2.0 );
        Ground->AddPoint( Point );
    }
    //Ground->AddPoint( b2Vec2(0.0, 20.0) );
    //Ground->AddPoint( b2Vec2(ScreenSize.width, 20.0) );

    //World->AddPhyObj( Ground );
}

InfiniteScene::~InfiniteScene()
{
    
}

void InfiniteScene::draw()
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

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
