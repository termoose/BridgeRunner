//
//  Scene.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 9/6/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_Scene_h
#define BridgeRunner_Scene_h

#include "cocos2d.h"
#include "Box2D.h"
#include <Physics.h>

using namespace cocos2d;

class Scene : public cocos2d::CCLayer
{
public:
    Scene();
    ~Scene();

    static cocos2d::CCScene *scene();

    virtual void draw();

    virtual void ccTouchesEnded( CCSet *touches, CCEvent *event );
    virtual void ccTouchesBegin( CCSet *touches, CCEvent *event );

    void tick( ccTime dt );
    
protected:
    void ClearTouches();
    
    Physics *World;
    CCSize ScreenSize;
    
    // Pair of < StartTouches, EndTouches >
    std::pair< std::vector< b2Vec2 >, std::vector< b2Vec2 > > Touches;
};

#endif
