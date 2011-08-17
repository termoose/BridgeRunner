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

VehicleObject::VehicleObject( const b2Vec2 &Pos ) : PhyObj( Pos, 0.0, true )
{
    
    
    BodyShape.SetAsBox( 1.0, 0.4 );
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
}