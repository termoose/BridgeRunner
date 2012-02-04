//
//  MenuScene.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 1/17/12.
//  Copyright (c) 2012 Extab. All rights reserved.
//

#include <iostream>
#include "MenuScene.h"
#include "InfiniteScene.h"

void MenuScene::StartScene( cocos2d::CCObject* pSender )
{
    CCDirector::sharedDirector()->replaceScene( InfiniteScene::scene() );
}

MenuScene::MenuScene() : ScreenSize( CCDirector::sharedDirector()->getWinSize() )
{
    // Menu Image
    MainMenuImage = CCSprite::spriteWithFile( "menuimage.png" );
    MainMenuImage->setPosition( CCPoint( 80, ScreenSize.height/2) );
    MainMenuImage->setScale( 0.6 );
    
    NewGameButton = CCMenuItemImage::itemFromNormalImage( "new_game.png",
                                                         "new_game_down.png",
                                                         this,
                                                         menu_selector(MenuScene::StartScene) );

    NewGameButton->setPosition( CCPoint(ScreenSize.width-192, ScreenSize.height/3*2) );
    MainMenu = CCMenu::menuWithItem( NewGameButton );
    MainMenu->setPosition( CCPointZero );

    addChild( MainMenu );
    addChild( MainMenuImage );
}

MenuScene::~MenuScene()
{
}

CCScene *MenuScene::scene()
{
    CCScene *scene = CCScene::node();
    CCLayer *layer = new MenuScene();
    scene->addChild( layer );
    layer->release();
    
    return scene;
}