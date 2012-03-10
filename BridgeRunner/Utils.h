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

void ccFilledDrawPoly( const cocos2d::CCPoint *poli, int numberOfPoints, const cocos2d::CCPoint *tex, const GLuint TexID );
void DrawFilledGround( const cocos2d::CCPoint& Start, const cocos2d::CCPoint& Stop, GLuint TexID, float TextureOffset );
void DrawFilledGround( const b2Vec2& Start, const b2Vec2& Stop, GLuint TexID, float TextureOffset );

void DrawTest( GLuint TexID, const cocos2d::CCPoint &Pos );

#endif
