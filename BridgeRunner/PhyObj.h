//
//  PhyObj.h
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef BuridgeES_PhyObj_h
#define BuridgeES_PhyObj_h

#include <vector>

#include "Physics.h"

// Forward declarations
class Physics;

class PhyObj
{
public:
    PhyObj( const b2Vec2 &Pos, float Angle, bool Dynamic );
    ~PhyObj();
    
    void Create();
    
    b2Body *GetBody() const;
    b2Vec2 GetPosition() const;
    float32 GetAngle() const;
    
    void AddChild( PhyObj *Obj );
    void SetParent( PhyObj *Obj );
    
    void SetOwner( Physics *PhysicsPtr );

protected:
    b2Body *Body;
    b2BodyDef BodyDef;
    b2FixtureDef BodyFixture;
    b2PolygonShape BodyShape;
    
    PhyObj *Parent;
    std::vector< PhyObj * > Children;
    
private:
    Physics *Owner;
};


#endif
