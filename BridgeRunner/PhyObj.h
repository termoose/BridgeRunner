//
//  PhyObj.h
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BuridgeES_PhyObj_h
#define BuridgeES_PhyObj_h

#include <vector>

#include <Physics.h>

// Forward declarations
class Physics;

class PhyObj
{
public:
    PhyObj( const b2Vec2 &Pos, float Angle, bool Dynamic );
    virtual ~PhyObj();
    
    virtual void Create();
    virtual void Render() = 0;
    
    b2Body *GetBody() const;
    b2Vec2 GetPosition() const;
    float32 GetAngle() const;
    
    void AddTorque( float32 Torque );
    
    void AddChild( PhyObj *Obj );
    void SetParent( PhyObj *Obj );
    
    void SetOwner( Physics *PhysicsPtr );
    Physics *GetOwner();
    
    void SetSpeed( float DesiredVelocity );
    void SetObjectID( int32 ID );
    int32 GetObjectID();
    
    void SetLinearVelocity( const b2Vec2 &Vel );

protected:
    b2Body *Body;
    b2BodyDef BodyDef;
    b2FixtureDef BodyFixture;
    b2PolygonShape BodyShape;
    
    PhyObj *Parent;
    std::vector< PhyObj * > Children;
    
    Physics *Owner;
    
private:
    int32 ObjectID;

};


#endif
