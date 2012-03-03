//
//  MenuScene.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 1/17/12.
//  Copyright (c) 2012 Extab. All rights reserved.
//

#ifndef BridgeRunner_MenuScene_h
#define BridgeRunner_MenuScene_h

#include <deque>

#include "cocos2d.h"
#include "PerlinNoise.h"

using namespace cocos2d;

class MenuScene : public cocos2d::CCLayer
{
public:
    MenuScene();
    ~MenuScene();
    
    static cocos2d::CCScene *scene();
    virtual void draw();
    
    void MoveScene( float Speed );
    
    void StartScene( cocos2d::CCObject* pSender );
    
private:
    void AddPoint( float Offset );
    
protected:
    CCMenu *MainMenu;
    CCSize ScreenSize;
    CCSprite *MainMenuImage;
    CCSprite *MainMenuHeading;
    
    CCTexture2D *GroundTexture;
    
    PerlinNoise Noise;
    
    CCMenuItemImage *NewGameButton;
    
    std::deque< CCPoint > GroundPoints;
    
    float Counter;
};

#endif