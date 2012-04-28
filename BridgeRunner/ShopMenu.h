//
//  ShopMenu.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 3/10/12.
//  Copyright (c) 2012 Extab. All rights reserved.
//

#ifndef BridgeRunner_ShopMenu_h
#define BridgeRunner_ShopMenu_h

#include "cocos2d.h"

using namespace cocos2d;

class ShopMenu : public cocos2d::CCLayer
{
public:
    ShopMenu();
    ~ShopMenu();
    
    static cocos2d::CCScene *scene();
    virtual void draw();
    
private:
    CCSize ScreenSize;
};

#endif
