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
    
    BodyShape.SetAsEdge( StartPosition, StopPosition );
    BodyShape.m_radius = 0.4;
}

void BridgeSegment::Render()
{
    b2Vec2 WorldStart = Body->GetWorldPoint( StartPosition );
    b2Vec2 WorldStop = Body->GetWorldPoint( StopPosition );

    ccDrawLine( CCPoint(WorldStart.x * 32, WorldStart.y * 32), CCPoint(WorldStop.x * 32, WorldStop.y * 32) );
}

BridgeSegment::~BridgeSegment()
{
    
}
