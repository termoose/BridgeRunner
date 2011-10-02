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

#include "BridgeSegment.h"

using namespace cocos2d;

class Scene : public cocos2d::CCLayer
{
public:
    Scene();
    ~Scene();

    static cocos2d::CCScene *scene();

    virtual void draw();

    virtual void ccTouchesEnded( CCSet *touches, CCEvent *event );
    virtual void ccTouchesBegan( CCSet *touches, CCEvent *event );
    virtual void ccTouchesMoved( CCSet *touches, CCEvent *event );

    void tick( ccTime dt );
    
protected:
    // Conversion functions
    b2Vec2 CCToBoxVec( CCPoint Point );
    CCPoint BoxToCCVec( b2Vec2 Point );
    
    bool AddBridgeSegment( b2Vec2 Start, b2Vec2 Stop );
    bool DelBridgeSegment( b2Vec2 Position );
    
    std::deque < BridgeSegment * > BridgeSegments;
    
    CCSize ScreenSize;
    
    Physics *World;
    
    // Our start and end touches
    b2Vec2 StartTouch;
    b2Vec2 StopTouch;
    
    float BridgeLengthEpsilon;
    int IterationCnt;
    int IterationsSinceLastClick;
    
    bool ScreenTouched;
    
private:
    b2Vec2 SegmentStart;
    b2Vec2 SegmentStop;
};

#endif
