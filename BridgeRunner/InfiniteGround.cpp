//
//  InfiniteGround.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 10/9/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "InfiniteGround.h"

using namespace cocos2d;

InfiniteGround::InfiniteGround() : Noise( 0.1, 1.0 )
{
}

InfiniteGround::~InfiniteGround()
{
}

void InfiniteGround::RecreateGround()
{

}

void InfiniteGround::ScrollGround( float Speed )
{

}

void InfiniteGround::AddPoint( float NewPoint )
{
    b2Vec2 NewPointVector( NewPoint / PTM_RATIO, (Noise.GetNoise( NewPoint / 30.0) * 80 + 100) / PTM_RATIO );
    Points.push_back( NewPointVector );
    
    if( Points.size() > 1 )
    {
        GroundSegment *NewSegment = new GroundSegment( Points[ Points.size() - 2 ], Points.back() );
        //World->AddPhyObj( NewSegment );
        GroundSegments.push_back( NewSegment );
    }
}

bool InfiniteGround::RemovePoint()
{
    return false;
}