//
//  BridgeSegment.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/12/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "BridgeSegment.h"

BridgeSegment::BridgeSegment( const b2Vec2 &Start, const b2Vec2 &Stop ) : PhyObj( b2Vec2(0.0, 0.0), 0.0, false )
{
    BodyShape.SetAsEdge( Start, Stop );
    BodyShape.m_radius = 1.0;
}

BridgeSegment::~BridgeSegment()
{
    
}
