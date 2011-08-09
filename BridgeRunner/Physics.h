//
//  Physics.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef PHYSICS_H
#define PHYSICS_H

#include <map>

#include "Box2D.h"

class Physics
{
public:
    Physics();
    ~Physics();

    b2World *GetWorld() const;
    
    bool RemPhyObj( const int32 &Id );
    
    void RenderAll(); // Renders all physical objects in object list

    void DoStep();

private:
    b2World *World;
    b2Vec2 Gravity;

    // Map of all simulated objects in the world, each with unique Id

    bool DoSleep;
    float32 TimeStep;
    int32 VelIters;
    int32 PosIters;
    
    int32 ObjectIdx;
};

#endif