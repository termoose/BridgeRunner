//
//  Physics.h
//  Buridge
//
//  Created by Ole Andre Birkedal on 6/22/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef PHYSICS_H
#define PHYSICS_H

#include <map>

#include "cocos2d.h" // For drawing

#include "Box2D.h"
#include "PhyObj.h"

#include <deque>

// Ratio between Box2D coordinates and screen coordinates
#define PTM_RATIO (float32)(32.0)

// Forward declarations
class PhyObj;

class Physics
{
public:
    Physics();
    ~Physics();

    b2World *GetWorld() const;
    
    void AddPhyObj( PhyObj *Obj );
    bool RemPhyObj( const int32 &Id );
    bool RemPhyObj( PhyObj *Object );
    PhyObj *GetPhyObj( const int32 &Id ) const;
    
    void RenderAll(); // Renders all physical objects in object list
    
    PhyObj *GetObjAtPosition( const b2Vec2 &Position );
    
    float32 GetTimeStep();

    void DoStep();

private:
    b2World *World;
    b2Vec2 Gravity;

    // Map of all simulated objects in the world, each with unique Id
    std::map< int32, PhyObj * > Objects;

    bool DoSleep;
    float32 TimeStep;
    int32 VelIters;
    int32 PosIters;
    
    int32 ObjectIdx;
};


// QueryCallback class used for detecting mouse clicks etc.
class QueryCallback : public b2QueryCallback
{
public:
    QueryCallback()
    {
        m_body = NULL;
    }
    
    bool ReportFixture( b2Fixture* fixture )
    {
        m_body = fixture->GetBody();
        
        return true;
    }
    
    b2Body *m_body;
};

#endif