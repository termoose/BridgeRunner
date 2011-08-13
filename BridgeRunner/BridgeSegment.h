//
//  BridgeSegment.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 8/12/11.
//  Copyright 2011 Extab. All rights reserved.
//

#ifndef BridgeRunner_BridgeSegment_h
#define BridgeRunner_BridgeSegment_h

#include <Physics.h>
#include <PhyObj.h>

class BridgeSegment : public PhyObj
{
public:
    BridgeSegment( const b2Vec2 &Start, const b2Vec2 &Stop );
    ~BridgeSegment();
    
    void Create();
    
private:
    // ...
};

#endif
