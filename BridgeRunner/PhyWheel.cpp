//
//  PhyWheel.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/16/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "PhyWheel.h"

PhyWheel::PhyWheel( const b2Vec2 &Pos ) : PhyObj( Pos, 0.0, true )
{
    BodyCircleShape.m_radius = 0.5;
    BodyFixture.shape = &BodyCircleShape;
}

PhyWheel::~PhyWheel()
{
}

void PhyWheel::Render()
{
    // Debug render
    //CCPoint Center = CCPoint( GetPosition().x * PTM_RATIO, GetPosition().y * PTM_RATIO );
    //ccDrawCircle( Center, BodyCircleShape.m_radius * PTM_RATIO, GetAngle(), 8, false );

    
}