//
//  GroundSegment.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 12/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GroundSegment.h"

using namespace cocos2d;

GroundSegment::GroundSegment( const b2Vec2 &Start, const b2Vec2 &Stop ) : BridgeSegment( Start, Stop )
{
    EdgeShape.m_radius = 0.01;
}

GroundSegment::~GroundSegment()
{
    
}

void GroundSegment::Render()
{
    b2Vec2 WorldStart = Body->GetWorldPoint( StartPosition );
    b2Vec2 WorldStop = Body->GetWorldPoint( StopPosition );
    
    glColor4f( 0.0, 1.0, 0.0, 0.0 );
    
    ccDrawLine( CCPoint(WorldStart.x * PTM_RATIO, WorldStart.y * PTM_RATIO),
               CCPoint(WorldStop.x * PTM_RATIO, WorldStop.y * PTM_RATIO) );
}