//
//  VehicleObject.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/13/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "VehicleObject.h"

VehicleObject::VehicleObject( const b2Vec2 &Pos ) : PhyObj( Pos, 0.0, true )
{
    Vertices.clear();
    
    // Make add vertex function?
    Vertices.push_back( b2Vec2(-2.0,-1.0 ) );
    Vertices.push_back( b2Vec2(-2.0, 1.0 ) );
    Vertices.push_back( b2Vec2( 2.0, 1.0 ) );
    Vertices.push_back( b2Vec2( 2.0,-1.0 ) );
    
    BodyShape.Set( &Vertices[0], Vertices.size() );
}

VehicleObject::~VehicleObject()
{
    Vertices.clear();
}

void VehicleObject::Create()
{
    Body->CreateFixture( &BodyFixture );
}