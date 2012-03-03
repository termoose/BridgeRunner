//
//  Utils.cpp
//  BridgeRunner
//
//  Created by Ole Andre Birkedal on 2/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "Utils.h"

using namespace cocos2d;

void DrawFilledGround( const b2Vec2& Start, const b2Vec2& Stop )
{
    DrawFilledGround( CCPoint(Start.x, Start.y), CCPoint(Stop.x, Stop.y) );
}

void DrawFilledGround( const CCPoint& Start, const CCPoint& Stop )
{
    CCPoint Vertices[ 4 ];
    Vertices[ 0 ] = Start;
    Vertices[ 1 ] = Stop;
    Vertices[ 2 ] = CCPoint( Start.x, 0.0 );
    Vertices[ 3 ] = CCPoint( Stop.x, 0.0 );
    
    ccFilledDrawPoly( Vertices, 4, false );
}

void ccFilledDrawPoly(const CCPoint *poli, int numberOfPoints, bool closePolygon)
{
    ccVertex2F* newPoint = new ccVertex2F[numberOfPoints];
    if (! newPoint)
    {
        return;
    }
    // Default GL states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
    // Needed states: GL_VERTEX_ARRAY, 
    // Unneeded states: GL_TEXTURE_2D, GL_TEXTURE_COORD_ARRAY, GL_COLOR_ARRAY	
    glDisable(GL_TEXTURE_2D);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    
    // iPhone and 32-bit machines
    if( sizeof(CCPoint) == sizeof(ccVertex2F) ) 
	{
        // convert to pixels ?
        if( CC_CONTENT_SCALE_FACTOR() != 1 ) 
		{
            memcpy( newPoint, poli, numberOfPoints * sizeof(ccVertex2F) );
            for( int i=0; i<numberOfPoints;i++)
            {
                newPoint[i].x = poli[i].x * CC_CONTENT_SCALE_FACTOR();
                newPoint[i].y = poli[i].y * CC_CONTENT_SCALE_FACTOR();
            }
            glVertexPointer(2, GL_FLOAT, 0, newPoint);
            
        } 
		else
		{
            glVertexPointer(2, GL_FLOAT, 0, poli);
		}
        
        
    } 
	else 
	{
        // 64-bit machines (Mac)
        
        for( int i=0; i<numberOfPoints;i++)
        {
            newPoint[i].x = poli[i].x;
            newPoint[i].y = poli[i].y;
        }
        
        glVertexPointer(2, GL_FLOAT, 0, newPoint );
        
    }
    
    if( closePolygon )
	{
        glDrawArrays(GL_TRIANGLES, 0, (GLsizei)numberOfPoints);
	}
    else
	{
        glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei)numberOfPoints);
	}
    
    // restore default state
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D);
    delete[] newPoint;
}

