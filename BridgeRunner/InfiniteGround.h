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

class InfiniteGround : public PhyObj
{
public:
    InfiniteGround();
    ~InfiniteGround();
    
    void AddPoint( float Point );
    bool RemovePoint();
    
    virtual void Render();
    
private:
    b2ChainShape GroundShape;
    b2Vec2 Points[ 12 ];
    
    PerlinNoise Noise;
};

#endif
