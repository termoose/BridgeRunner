//
//  PhyGround.cpp
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "PhyGround.h"

PhyGround::PhyGround() : PhyObj( b2Vec2(0.0, 0.0), 0.0, false )
{
    Vertices.clear();
}

PhyGround::~PhyGround()
{
    Vertices.clear();
}

void PhyGround::AddPoint( const b2Vec2 &Point )
{
    Vertices.push_back( Point );
}

void PhyGround::Create()
{
    for( std::vector< b2Vec2 >::iterator it = Vertices.begin() - 1;
        it != Vertices.end(); ++it )
    {
        BodyShape.SetAsEdge( *it, *(it + 1) );
        Body->CreateFixture( &BodyFixture );
    }
}