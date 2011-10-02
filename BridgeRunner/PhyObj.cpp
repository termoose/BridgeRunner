//
//  PhyObj.cpp
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include "PhyObj.h"

PhyObj::PhyObj( const b2Vec2 &Pos, float Angle, bool Dynamic )
{
    BodyDef.type = Dynamic ? b2_dynamicBody : b2_staticBody;
    BodyDef.position = Pos;
    BodyDef.position *= 1 / PTM_RATIO;
    BodyDef.angle = Angle;
    
    // Every body has a pointer to its PhyObj
    BodyDef.userData = this;
    
    // CreateBody
    BodyFixture.density = 1.0;
    BodyFixture.friction = 0.8;
    
    // We define BodyShape in derived classes
    BodyFixture.shape = &BodyShape;
    
    // No parent and no children by default
    Parent = NULL;
    Children.clear();
}

PhyObj::~PhyObj()
{
    Owner->GetWorld()->DestroyBody( Body );
    Body = NULL;
}

b2Vec2 PhyObj::GetPosition() const
{
    return Body->GetPosition();
}

void PhyObj::AddTorque( float32 Torque )
{
    Body->ApplyTorque( Torque );
}

void PhyObj::Create()
{
    // If it has a parent, transform it into local space for that object
    if( Parent )
    {
        BodyDef.position = Parent->GetBody()->GetWorldPoint( BodyDef.position );
    }

    Body = Owner->GetWorld()->CreateBody( &BodyDef );
    
    Body->CreateFixture( &BodyFixture );
}

float32 PhyObj::GetAngle() const
{
    return Body->GetAngle();
}

b2Body *PhyObj::GetBody() const
{
    return Body;
}

void PhyObj::AddChild( PhyObj *Obj )
{
    Obj->SetParent( this );
    Children.push_back( Obj );

    Owner->AddPhyObj( Obj );
}

void PhyObj::SetParent( PhyObj *Obj )
{
    Parent = Obj;
}

Physics *PhyObj::GetOwner()
{
    return Owner;
}

void PhyObj::SetOwner( Physics *PhysicsPtr )
{
    Owner = PhysicsPtr;
}

