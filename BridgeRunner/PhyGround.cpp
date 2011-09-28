//
//  PhyGround.cpp
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "PhyGround.h"

using namespace cocos2d;

PhyGround::PhyGround() : PhyObj( b2Vec2(0.0, 0.0), 0.0, false )
{
    Vertices.clear();
}

PhyGround::~PhyGround()
{
    Vertices.clear();
}

void PhyGround::AddPoint( b2Vec2 Point )
{
    Point *= 1 / PTM_RATIO;
    Vertices.push_back( Point );
}

void PhyGround::Render()
{
    // FIXME: auto_ptr
    CCPoint *DrawPoints = new CCPoint[ BodyShape.GetVertexCount() ];
    
    for( std::vector< b2Vec2 >::iterator it = Vertices.begin();
        it != Vertices.end(); ++it )
    {
        b2Vec2 Current = Body->GetWorldVector( *it );
        DrawPoints[ it - Vertices.begin() ] = CCPoint( Current.x * PTM_RATIO, Current.y * PTM_RATIO );
    }
    
    ccDrawPoly( DrawPoints, BodyShape.GetVertexCount(), false );
    
    delete DrawPoints;
}

void PhyGround::Create()
{
    Body = Owner->GetWorld()->CreateBody( &BodyDef );

    for( std::vector< b2Vec2 >::iterator it = Vertices.begin() - 1;
        it != Vertices.end(); ++it )
    {
        BodyShape.SetAsEdge( *it, *(it + 1) );
        Body->CreateFixture( &BodyFixture );
    }
}