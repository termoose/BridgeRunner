//
//  TestScene.h
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BuridgeES_TestScene_h
#define BuridgeES_TestScene_h

#include "cocos2d.h"
#include "Box2D.h"
#include "Scene.h"
#include <Physics.h>

using namespace cocos2d;

class TestScene : public cocos2d::CCLayer
{
public:
    ~TestScene();
    TestScene();
    
    static cocos2d::CCScene *scene();
    
    virtual void draw();
    virtual void ccTouchesEnded( cocos2d::CCSet *touches, cocos2d::CCEvent *event );
    virtual void ccTouchesBegan( cocos2d::CCSet *touches, cocos2d::CCEvent *event );
    void tick( cocos2d::ccTime dt );
    
private:
    std::pair< CCPoint, CCPoint > GetCurrentTouch( int32 FirstIndex, int32 SecondIndex );
    void ClearCurrentTouch();
    
    Physics *World;
    // < FirstTouches, SecondTouches >
    std::pair< std::vector< CCTouch * >, std::vector< CCTouch * > > LastTouches;

};

#endif
