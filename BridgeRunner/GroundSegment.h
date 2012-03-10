//
//  GroundSegment.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 12/12/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef BridgeRunner_GroundSegment_h
#define BridgeRunner_GroundSegment_h

#include "BridgeSegment.h"

class GroundSegment : public BridgeSegment
{
public:
    GroundSegment( const b2Vec2 &Start, const b2Vec2 &Stop );

    virtual void Render();
    
    inline void SetTextureOffset() { TextureOffset = -Body->GetPosition().x * PTM_RATIO; }
    inline void SetTextureID( GLuint ID ) { TextureID = ID; }
    
private:
    float TextureOffset;
    GLuint TextureID;
};

#endif
