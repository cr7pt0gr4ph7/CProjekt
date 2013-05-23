/*
 * Tile.cpp
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#include "Tile.h"

using namespace std;
//!< Einfacher Zugriff auf Funktionen der Standardbibliothek.
#include <list>							//!< Zur Erstelleung einer einfachern Liste
list < Block * > listBlock;				//!< Blöcke für die Darstellung

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

Tile::Tile(
	const char *_title , const char* _description ,
	const unsigned short _height , const unsigned short _width ) :
			title( _title ),
			description( _description ),
			rotation( 0 ),
			seal( false ),
			height( _height ),
			width( _width )
{
	for ( unsigned short h = 0 ; h < _height ; h++ )
	{
		for ( unsigned short w = 0 ; w < _width ; w++ )
		{
			listBlock.push_back( new Block( ) );
		}
	}
}

Tile::~Tile()
{
	listBlock.erase(listBlock.begin(), listBlock.end());		//!< Alle Elemente aus der Liste l&ouml;schen.
}


Block *Tile::getPBlock(unsigned short _width, unsigned short _height)
{
	//TODO Nach mit Funktion versehen.
	return new Block();	// Dummy
}

Block Tile::getBlock(unsigned short _width, unsigned short _height)
{
	//TODO Nach mit Funktion versehen.
	return Block(); // Dummy
}

