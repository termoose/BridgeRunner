//
//  PhyObj.cpp
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "PhyObj.h"

PhyObj::PhyObj( const b2Vec2 &Pos, float Angle, bool Dynamic )
{
    BodyDef.type = Dynamic ? b2_dynamicBody : b2_staticBody;
    BodyDef.position = Pos;
    BodyDef.angle = Angle;
    
    // CreateBody
    BodyFixture.density = 1.0;
    BodyFixture.friction = 0.1;
    
    // We define BodyShape in derived classes
    BodyFixture.shape = &BodyShape;
    
    // No parent and no children by default
    Parent = NULL;
    Children.clear();
}

PhyObj::~PhyObj()
{

}

void PhyObj::Create()
{
    Body = Owner->GetWorld()->CreateBody( &BodyDef );
    Body->CreateFixture( &BodyFixture );
}

void PhyObj::SetOwner( Physics *PhysicsPtr )
{
    Owner = PhysicsPtr;
}

