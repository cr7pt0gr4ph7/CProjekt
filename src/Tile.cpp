/*
 * Tile.cpp
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#include "Tile.h"

Tile::Tile() :
			title( "KEIN NAMEN VORHANDEN" ),
			description( "KEINE BESCHREIBUNG VORHANDEN" ),
			rotation( 0 ),
			seal( false ),
			height( 0 ),
			width( 0 )
{

}

Tile::Tile( const char *_title , const char* _description ) :
			title( _title ),
			description( _description ),
			rotation( 0 ),
			seal( false ),
			height( 0 ),
			width( 0 )
{

}

Tile::~Tile()
{

}

