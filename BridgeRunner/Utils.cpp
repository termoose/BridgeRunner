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

void DrawTest( GLuint TexID, const CCPoint &Pos )
{
    CCPoint Vertices[ 4 ];
    Vertices[ 0 ] = ccp( 0.0, 100.0 );
    Vertices[ 1 ] = ccp( 0.0, 0.0 );
    Vertices[ 2 ] = ccp( 100.0, 100.0 );
    Vertices[ 3 ] = ccp( 100.0, 0.0 );
    
    for( int i = 0; i < 4; ++i )
        Vertices[ i ] = ccp( Vertices[ i ].x + Pos.x, Vertices[ i ].y + Pos.y );
    
    CCPoint Texture[ 4 ];
    Texture[ 0 ] = ccp( 0.0, 1.0 );
    Texture[ 1 ] = ccp( 0.0, 0.0 );
    Texture[ 2 ] = ccp( 1.0, 1.0 );
    Texture[ 3 ] = ccp( 1.0, 0.0 );
    
    //ccDrawPoly( Vertices, 4, true );
    
    ccFilledDrawPoly(Vertices, 4, Texture, TexID );
}

void DrawFilledGround( const b2Vec2& Start, const b2Vec2& Stop, GLuint TexID, float TextureOffset )
{
    DrawFilledGround( CCPoint(Start.x, Start.y), CCPoint(Stop.x, Stop.y), TexID, TextureOffset );
}

void DrawFilledGround( const CCPoint& Start, const CCPoint& Stop, const GLuint TexID, float TextureOffset )
{
    CCPoint TextureCoords[ 4 ];
    
    CCPoint Vertices[ 4 ];
    Vertices[ 0 ] = Start;
    Vertices[ 1 ] = Stop;
    Vertices[ 2 ] = CCPoint( Start.x, 0.0 );
    Vertices[ 3 ] = CCPoint( Stop.x, 0.0 );

    // Use vertex coordinates as texture coordinates
    for( int i = 0; i < 4; ++i )
        TextureCoords[ i ] = ccp( (Vertices[ i ].x + TextureOffset) / 50.0, Vertices[ i ].y / 50.0 );
    
    ccFilledDrawPoly( Vertices, 4, TextureCoords, TexID );
}

void ccFilledDrawPoly( const CCPoint *poli, int numberOfPoints, const CCPoint *tex, const GLuint TexID )
{
    ccVertex2F* newPoint = new ccVertex2F[numberOfPoints];
    ccVertex2F* newTex = new ccVertex2F[numberOfPoints];

    if (! newPoint)
    {
        return;
    }
    // Default GL states: GL_TEXTURE_2D, GL_VERTEX_ARRAY, GL_COLOR_ARRAY, GL_TEXTURE_COORD_ARRAY
    // Needed states: GL_VERTEX_ARRAY, 
    // Unneeded states: GL_TEXTURE_2D, GL_TEXTURE_COORD_ARRAY, GL_COLOR_ARRAY	
    //glDisable(GL_TEXTURE_2D);
    //glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    glBindTexture( GL_TEXTURE_2D, TexID );
    
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
                
                newTex[i].x = tex[i].x;
                newTex[i].y = tex[i].y;
            }
            glVertexPointer(2, GL_FLOAT, 0, newPoint);
            glTexCoordPointer(2, GL_FLOAT, 0, newTex);
            
        } 
		else
		{
            glVertexPointer(2, GL_FLOAT, 0, poli);
            glTexCoordPointer(2, GL_FLOAT, 0, tex);
		}
        
        
    } 
	else 
	{
        // 64-bit machines (Mac)
        
        for( int i=0; i<numberOfPoints;i++)
        {
            newPoint[i].x = poli[i].x;
            newPoint[i].y = poli[i].y;
            
            newTex[i].x = tex[i].x;
            newTex[i].y = tex[i].y;
        }
        
        glVertexPointer(2, GL_FLOAT, 0, newPoint );
    }

    glDrawArrays(GL_TRIANGLE_STRIP, 0, (GLsizei)numberOfPoints);
    
    // restore default state
    glEnableClientState(GL_COLOR_ARRAY);
    //glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    //glEnable(GL_TEXTURE_2D);
    delete[] newPoint;
    delete[] newTex;
}

