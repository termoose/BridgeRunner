//
//  InfiniteGround.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 10/9/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_InfiniteGround_h
#define BridgeRunner_InfiniteGround_h

#include "PhyObj.h"
#include "PerlinNoise.h"
#include "GroundSegment.h"

#include <deque>

class InfiniteGround
{
public:
    InfiniteGround();
    ~InfiniteGround();
    
    void AddPoint( float NewPoint );
    bool RemovePoint();
    
    void RecreateGround();
    void ScrollGround( float Speed );
    
private:
    b2ChainShape GroundShape;
    
    std::deque< b2Vec2 > Points;
    std::deque< GroundSegment * > GroundSegments;
    
    PerlinNoise Noise;
};

#endif
