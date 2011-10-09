//
//  InfiniteGround.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 10/9/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "InfiniteGround.h"

InfiniteGround::InfiniteGround()
{

}

InfiniteGround::~InfiniteGround()
{
    
}

void InfiniteGround::AddPoint( b2Vec2 &Point )
{
    Point *= 1 / PTM_RATIO;
    Vertices.push_back( Point );
}