//
//  PhyJoint.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/17/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <PhyJoint.h>

PhyJoint::PhyJoint( PhyObj *Obj1, PhyObj *Obj2, const b2Vec2 &Anchor1, const b2Vec2 &Anchor2 )
{
    b2Vec2 WorldAxis(1.0, 0.0);
    JointDef.Initialize( Obj1->GetBody(), Obj2->GetBody(), Obj1->GetBody()->GetWorldCenter(), WorldAxis );
    
    JointDef.collideConnected = false;
    
    JointDef.lowerTranslation = -5.0f;
    JointDef.upperTranslation = 2.5f;
    JointDef.enableLimit = true;
    JointDef.maxMotorForce = 1.0f;
    JointDef.motorSpeed = 0.0f;
    JointDef.enableMotor = true;
}

PhyJoint::~PhyJoint()
{
    
}

void PhyJoint::Create()
{
    
}

void PhyJoint::Render()
{
    
}