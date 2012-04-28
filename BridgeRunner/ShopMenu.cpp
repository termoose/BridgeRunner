//
//  ShopMenu.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 3/10/12.
//  Copyright (c) 2012 Extab. All rights reserved.
//

#include <iostream>
#include "ShopMenu.h"

ShopMenu::ShopMenu() : ScreenSize( CCDirector::sharedDirector()->getWinSize() ) 
{
}

ShopMenu::~ShopMenu()
{
}

void ShopMenu::draw()
{
}


CCScene *ShopMenu::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new ShopMenu();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}
