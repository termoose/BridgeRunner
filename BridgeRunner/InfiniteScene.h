//
//  InfiniteScene.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 9/27/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_InfiniteScene_h
#define BridgeRunner_InfiniteScene_h

#include "Scene.h"
#include "PhyWheel.h"
#include "PerlinNoise.h"
#include "GroundSegment.h"

class InfiniteScene : public Scene
{
public:
    InfiniteScene();
    ~InfiniteScene();
    
    static cocos2d::CCScene *scene();
    void draw();
    
    void AddNewSegment( float Offset );
    void RemoveSegment();

private:
    PhyWheel *RollingCircle;
    CCSprite *BallImage;

    std::deque< GroundSegment * > GroundSegments;
    
    void MoveScene( float Speed );
    
    float LengthCounter;
    float GroundDelta;
    
    float RemoveGroundProbability;
    
    PerlinNoise Noise;
};

#endif
