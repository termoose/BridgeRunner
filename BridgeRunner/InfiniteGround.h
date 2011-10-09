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

class InfiniteGround
{
public:
    InfiniteGround();
    ~InfiniteGround();
    
    void AddPoint( b2Vec2 &Point );
    
public:
    b2ChainShape ChainShape;
    std::deque< b2Vec2 > Vertices;

};

#endif
