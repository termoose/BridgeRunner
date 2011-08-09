//
//  Physics.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include "Physics.h"

Physics::Physics()
{
    // Start counting the unique object Id at 0
    ObjectIdx = 0;

    DoSleep = true;
    Gravity = b2Vec2( 0.0, -10.0 );
    
    // Default values for accuracy in simulation
    TimeStep = 1.0 / 60.0;
    VelIters = 10;
    PosIters = 10;
    
    World = new b2World( Gravity, DoSleep );
}

Physics::~Physics()
{

    delete World;
}

void Physics::DoStep()
{
    World->Step( TimeStep, VelIters, PosIters );
    World->ClearForces();
}

b2World *Physics::GetWorld() const
{
    return World;
}

void Physics::RenderAll()
{

}

