//
//  PhyWheel.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/16/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_PhyWheel_h
#define BridgeRunner_PhyWheel_h

#include <Physics.h>
#include <PhyObj.h>

using namespace cocos2d;

class PhyWheel : public PhyObj
{
public:
    PhyWheel( const b2Vec2 &Pos );
    ~PhyWheel();
    
    virtual void Render();

private:
    CCSprite *BallImage;
    b2CircleShape BodyCircleShape;
};

#endif
