//
//  MenuScene.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 1/17/12.
//  Copyright (c) 2012 Extab. All rights reserved.
//

#ifndef BridgeRunner_MenuScene_h
#define BridgeRunner_MenuScene_h

#include <vector>
#include "cocos2d.h"

using namespace cocos2d;

class MenuScene : public cocos2d::CCLayer
{
public:
    MenuScene();
    ~MenuScene();
    
    static cocos2d::CCScene *scene();
    
    void StartScene( cocos2d::CCObject* pSender );
    
protected:
    CCMenu *MainMenu;
    CCSize ScreenSize;
    CCSprite *MainMenuImage;
    
    CCMenuItemImage *NewGameButton;
    
    std::vector< CCMenuItem * > MenuItems;
    
};

#endif