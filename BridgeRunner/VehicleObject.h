//
//  VehicleObject.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/13/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_VehicleObject_h
#define BridgeRunner_VehicleObject_h

#include <Physics.h>
#include <PhyObj.h>

class VehicleObject : public PhyObj
{
public:
    VehicleObject( const b2Vec2 &Pos );
    ~VehicleObject();
    
    virtual void Render();

private:
    
};

#endif
