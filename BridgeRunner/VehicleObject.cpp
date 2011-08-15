//
//  VehicleObject.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/13/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "VehicleObject.h"

using namespace cocos2d;

VehicleObject::VehicleObject( const b2Vec2 &Pos ) : PhyObj( Pos, 1.0, true )
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
    
    BodyShape.SetAsBox( 2.0, 1.0 );
}

void VehicleObject::Render()
{
    // FIXME: auto_ptr
    CCPoint *DrawPoints = new CCPoint[ BodyShape.GetVertexCount() ];

    for( unsigned int i = 0; i < BodyShape.GetVertexCount(); ++i )
    {
        b2Vec2 Current = Body->GetWorldPoint( BodyShape.GetVertex( i ) );
        DrawPoints[ i ] = CCPoint( Current.x * 32, Current.y * 32 );
    }
    
    ccDrawPoly( DrawPoints, BodyShape.GetVertexCount(), true );
    
    delete DrawPoints;
}

VehicleObject::~VehicleObject()
{
    Vertices.clear();
}

void VehicleObject::Create()
{    
    Body = Owner->GetWorld()->CreateBody( &BodyDef );
    
    Body->CreateFixture( &BodyFixture );
}