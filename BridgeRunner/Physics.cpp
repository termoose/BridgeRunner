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
// Create PhyObj objects and use AddPhyObj to add them the the physics
// using AddPhyObj
Physics::Physics() : 
    // Start counting the unique object Id at 0
    ObjectIdx( 0 ),
    Gravity( 0.0, -10.0 ),

    // Put inactive objects to sleep by default
    DoSleep( true ),

    // Default values for accuracy in simulation
    TimeStep( 1.0 / 60.0 ),
    VelIters( 8 ),
    PosIters( 2 )
{  
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

PhyObj *Physics::GetObjAtPosition( const b2Vec2 &Position )
{
    b2AABB PositionBox;

    b2Vec2 BoxDelta( 0.1, 0.1 );
    BoxDelta *= 1.0 / PTM_RATIO;
    
    b2Vec2 QueryPosition = Position;
    
    QueryPosition *= 1.0 / PTM_RATIO;
    
    PositionBox.lowerBound = QueryPosition - BoxDelta;
    PositionBox.upperBound = QueryPosition + BoxDelta;
    
    QueryCallback callback;
    
    World->QueryAABB( &callback, PositionBox );
    
    b2Body *SelectedBody = callback.m_body;
    
    if( SelectedBody )
    {
        std::cout << "Body selected! NEW!" << std::endl;
        
        return static_cast< PhyObj * >( SelectedBody->GetUserData() );
    }
    
    //if( SelectedFixture )
    {
        //std::cout << "Body selected!" << std::endl;
        
        //b2Body *SelectedBody = SelectedFixture->GetBody();
        //return static_cast< PhyObj * >( SelectedBody->GetUserData() );
    }

    return NULL;
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

// Debug render function
void Physics::RenderAll()
{
    glColor4f( 1.0, 1.0, 1.0, 1.0 );
    for( std::map< int32, PhyObj * >::iterator it = Objects.begin();
        it != Objects.end(); ++it )
    {
        it->second->Render();
    }
        
        
}


