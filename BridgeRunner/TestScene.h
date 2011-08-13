//
//  TestScene.h
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef BuridgeES_TestScene_h
#define BuridgeES_TestScene_h

#include "cocos2d.h"
#include "Box2D.h"
#include <Physics.h>

class TestScene : public cocos2d::CCLayer
{
public:
    ~TestScene();
    TestScene();
    
    static cocos2d::CCScene *scene();
    
    virtual void draw();
    virtual void ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent* event );
    void tick( cocos2d::ccTime dt );
    
private:
    Physics *World;

};

#endif
