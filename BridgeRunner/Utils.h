//
//  Utils.h
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BridgeRunner_Utils_h
#define BridgeRunner_Utils_h

#include "cocos2d.h"
#include "Box2D.h"
#include "Physics.h"

void ccFilledDrawPoly( const cocos2d::CCPoint *poli, int numberOfPoints, bool closePolygon );
void DrawFilledGround( const cocos2d::CCPoint& Start, const cocos2d::CCPoint& Stop );
void DrawFilledGround( const b2Vec2& Start, const b2Vec2& Stop );

#endif
