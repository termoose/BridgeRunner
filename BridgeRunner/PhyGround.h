//
//  PhyGround.h
//  BuridgeES
//
//  Created by Ole Andre Birkedal on 8/7/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BuridgeES_PhyGround_h
#define BuridgeES_PhyGround_h

#include <Physics.h>
#include <PhyObj.h>

#include <vector>

class PhyGround : public PhyObj
{
public:
    PhyGround();
    ~PhyGround();
    
    void AddPoint( const b2Vec2 &Point );
    virtual void Create();
    
private:
    std::vector< b2Vec2 > Vertices;
};


#endif
