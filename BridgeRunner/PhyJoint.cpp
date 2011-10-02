//
//  PhyJoint.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/17/11.
//  Copyright 2011 Extab. All rights reserved.
//

#include <iostream>
#include <PhyJoint.h>

PhyJoint::PhyJoint( PhyObj *Obj1, PhyObj *Obj2, const b2Vec2 &Anchor1, const b2Vec2 &Anchor2 )
{
    b2Vec2 WorldAxis(1.0, 0.0);
    JointDef.Initialize( Obj1->GetBody(), Obj2->GetBody(), Obj1->GetBody()->GetWorldCenter(), WorldAxis );
    
    JointDef.collideConnected = false;
    
    JointDef.lowerTranslation = -1.0f;
    JointDef.upperTranslation = 0.5f;
    JointDef.enableLimit = false;
    JointDef.maxMotorForce = 1.0f;
    JointDef.motorSpeed = 1.0f;
    JointDef.enableMotor = true;
    
    // Set the owner of the joint to the owner of the first object
    Owner = Obj1->GetOwner();
}

PhyJoint::~PhyJoint()
{
    
}

void PhyJoint::Create()
{
    Joint = Owner->GetWorld()->CreateJoint( &JointDef );
}

void PhyJoint::Render()
{
    
}