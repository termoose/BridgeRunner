//
//  BridgeSegment.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/12/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "BridgeSegment.h"

using namespace cocos2d;

BridgeSegment::BridgeSegment( const b2Vec2 &Start, const b2Vec2 &Stop ) : PhyObj( b2Vec2(0.0, 0.0), 0.0, false ),
    StartPosition( Start ),
    StopPosition( Stop )
{
    StartPosition *= 1 / PTM_RATIO;
    StopPosition *= 1 / PTM_RATIO;

    EdgeShape.m_radius = 0.3;
    EdgeShape.Set( StartPosition, StopPosition );
    
    BodyFixture.shape = &EdgeShape;
}

BridgeSegment::~BridgeSegment()
{
}

b2Vec2 BridgeSegment::GetStopPoint()
{
    b2Vec2 Pos = Body->GetWorldPoint( StopPosition );
    return b2Vec2( Pos.x * PTM_RATIO, Pos.y * PTM_RATIO );
}

b2Vec2 BridgeSegment::GetStartPoint()
{
    // = GetPosition() - StartPosition;
    b2Vec2 Pos = Body->GetWorldPoint( StartPosition );
    return b2Vec2( Pos.x * PTM_RATIO, Pos.y * PTM_RATIO );
}

void BridgeSegment::Render()
{
    b2Vec2 WorldStart = Body->GetWorldPoint( StartPosition );
    b2Vec2 WorldStop = Body->GetWorldPoint( StopPosition );

    ccDrawLine( CCPoint(WorldStart.x * PTM_RATIO, WorldStart.y * PTM_RATIO),
                CCPoint(WorldStop.x * PTM_RATIO, WorldStop.y * PTM_RATIO) );
}