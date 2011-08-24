//
//  Physics.cpp
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "Physics.h"

// How to use this:
// Create PhyObj objects and use AddPhyObj to add them the the physics,
// then call Create() on the PhyObj's before using them.

// Fixme: call Create() upon adding them to Physics class?

Physics::Physics()
{
    // Start counting the unique object Id at 0
    ObjectIdx = 0;

    DoSleep = true;
    Gravity = b2Vec2( 0.0, -10.0 );
    
    // Default values for accuracy in simulation
    TimeStep = 1.0 / 60.0;
    VelIters = 8;
    PosIters = 2;
    
    World = new b2World( Gravity, DoSleep );
}

Physics::~Physics()
{
    // Delete all objects in scene
    for( std::map< int32, PhyObj * >::iterator it = Objects.begin();
        it != Objects.end(); ++it )
    {
        delete it->second;
    }
    
    Objects.clear();

    delete World;
}

void Physics::AddPhyObj( PhyObj *Obj )
{
    Objects[ ObjectIdx ] = Obj;
    Obj->SetOwner( this );
    Obj->Create();

    ObjectIdx++;
}

PhyObj *Physics::GetPhyObj( const int32 &Id ) const
{
    std::map< int32, PhyObj * >::const_iterator Result = Objects.find( Id );
    
    if( Result == Objects.end() )
        return NULL;
    
    return Result->second;
}

bool Physics::RemPhyObj( const int32 &Id )
{
    PhyObj *Object = GetPhyObj( Id );
    
    if( Object == NULL )
    {
        std::cerr << "Trying to delete an object that does not exist!" << std::endl;
        return false;
    }
    
    delete Object;
    Object = NULL;
    
    Objects.erase( Id );
    
    return true;
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
    for( std::map< int32, PhyObj * >::iterator it = Objects.begin();
        it != Objects.end(); ++it )
    {
        it->second->Render();
    }
        
        
}


