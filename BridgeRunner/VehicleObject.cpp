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
    b2Vec2 Verts[4];
    Verts[0].Set( 0.0, 0.0);
    Verts[1].Set( 1.0, 0.0);
    Verts[2].Set( 1.0, 1.0);
    Verts[3].Set( 1.0, 0.0);

    Vertices.push_back( b2Vec2(-2.0,-1.0 ) );
    Vertices.push_back( b2Vec2(-2.0, 1.0 ) );
    Vertices.push_back( b2Vec2( 2.0, 1.0 ) );
    Vertices.push_back( b2Vec2( 2.0,-1.0 ) );
    
    BodyShape.SetAsBox( 2.0, 1.0, b2Vec2(0.0, 0.0), M_PI/4.0 );
}

VehicleObject::~VehicleObject()
{
    Vertices.clear();
}