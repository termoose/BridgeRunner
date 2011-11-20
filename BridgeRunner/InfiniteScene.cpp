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
#include "PhyWheel.h"
#include "PerlinNoise.h"

InfiniteGround *Ground;

InfiniteScene::InfiniteScene() : Scene()
{    
    PhyWheel *CircleTest = new PhyWheel( b2Vec2( ScreenSize.width / 2.4, 320.0 ) );
    World->AddPhyObj( CircleTest );

    Ground = new InfiniteGround();
    World->AddPhyObj( Ground );
}

InfiniteScene::~InfiniteScene()
{
    
}

void InfiniteScene::draw()
{
    Scene::draw();
    Ground->Render();
}

CCScene *InfiniteScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new InfiniteScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
