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
#include "Utils.h"

void MenuScene::StartScene( cocos2d::CCObject* pSender )
{
    CCDirector::sharedDirector()->replaceScene( InfiniteScene::scene() );
}

MenuScene::MenuScene() : ScreenSize( CCDirector::sharedDirector()->getWinSize() ), Noise( 0.1, 1.0 ), Counter(ScreenSize.width)
{
    ccTexParams tex_params = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };

    for( float i = 0; i < ScreenSize.width; i += ScreenSize.width / 128 )
        GroundPoints.push_back( CCPoint( i, Noise.GetNoise( i / 30.0) * 80 + 100 ) );

    // Texture parameters
    
    // Menu Image
    MainMenuImage = CCSprite::spriteWithFile( "menuimage.png" );
    MainMenuImage->setPosition( CCPoint( 80, ScreenSize.height/2) );
    MainMenuImage->setScale( 0.6 );
    
    MainMenuHeading = CCSprite::spriteWithFile( "howsherolls_heading.png" );
    MainMenuHeading->setPosition( CCPoint( ScreenSize.width/2, ScreenSize.height-50) );    
    
    NewGameButton = CCMenuItemImage::itemFromNormalImage( "new_game.png",
                                                         "new_game_down.png",
                                                         this,
                                                         menu_selector(MenuScene::StartScene) );

    GroundTexture = CCTextureCache::sharedTextureCache()->addImage( "ground.png" );
    GroundTexture->setTexParameters( &tex_params );
    
    NewGameButton->setPosition( CCPoint(ScreenSize.width-192, ScreenSize.height/3*2) );
    MainMenu = CCMenu::menuWithItem( NewGameButton );
    MainMenu->setPosition( CCPointZero );

    addChild( MainMenu );
    addChild( MainMenuImage );
    addChild( MainMenuHeading );
}

void MenuScene::AddPoint( float Offset )
{
    CCPoint LastPoint = GroundPoints.back();

    float NewPointPosition = LastPoint.x + Offset;
    CCPoint NewPoint( NewPointPosition, Noise.GetNoise( Counter / 30.0) * 80 + 100 );
    
    GroundPoints.push_back( NewPoint );
}

void MenuScene::MoveScene( float Speed )
{
    if( GroundPoints.size() == 0 || GroundPoints.back().x < ScreenSize.width )
    {
        AddPoint( Speed );
    }
    
    // Remove segment
    if( GroundPoints.front().x < 0 )
    {
        GroundPoints.pop_front();
    }

    GLuint GroundTextureID = GroundTexture->getName();
    
    for( std::deque< CCPoint >::iterator it = GroundPoints.begin();
        it != GroundPoints.end() - 1; ++it )
    {
        DrawFilledGround( *it, *(it+1), GroundTextureID, Counter );
        
        // Translate points
        it->x -= Speed;
    }
    
    GroundPoints.back().x -= Speed;
    
    Counter += Speed;
}

void MenuScene::draw()
{
    MoveScene( ScreenSize.width / 128.0 );
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