//
//  PhyJoint.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/17/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_PhyJoint_h
#define BridgeRunner_PhyJoint_h

#include <Physics.h>
#include <PhyObj.h>

class PhyJoint
{
public:
    PhyJoint( PhyObj *Obj1, PhyObj *Obj2, const b2Vec2 &Anchor1, const b2Vec2 &Anchor2 );
    ~PhyJoint();
    
    virtual void Render();
    virtual void Create();
    
private:
    b2Joint *Joint;
    b2PrismaticJointDef JointDef;
    
    Physics *Owner;
};

#endif
