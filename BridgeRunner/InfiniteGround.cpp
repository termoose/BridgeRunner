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

InfiniteGround::InfiniteGround() : PhyObj( b2Vec2(0.0, 0.0), 0.0, false ),
    Noise( 0.1, 1.0 )
{
    for( int i = 0; i < sizeof(Points)/sizeof(*Points); ++i )
    {
        //GroundShape.SetNextVertex( b2Vec2((i * 50.0) / PTM_RATIO, (sin( i * 10.0)*20 + 100.0) / PTM_RATIO) );
        Points[ i ].Set( (i * 49.0) / PTM_RATIO, (sin( i * 5.0)*40 + 100.0) / PTM_RATIO );
    }
    
    GroundShape.CreateChain( Points, sizeof(Points)/sizeof(*Points) );
    //GroundShape.SetNextVertex( b2Vec)
    BodyFixture.shape = &GroundShape;
}

InfiniteGround::~InfiniteGround()
{
}

void InfiniteGround::Render()
{
    for( int i = 0; i < sizeof(Points)/sizeof(*Points) - 1; ++i )
    {
        ccDrawLine( CCPoint( Points[ i ].x * 32, Points[ i ].y * 32), 
                    CCPoint( Points[ i+1 ].x * 32, Points[ i+1 ].y * 32) );
    }
}

void InfiniteGround::AddPoint( float Point )
{

}

bool InfiniteGround::RemovePoint()
{
    return false;
}