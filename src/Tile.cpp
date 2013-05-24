/*!
 * @file	TileI.cpp
 *
 * @date	21.05.2013
 * @author	Superuser
 * @brief	Sourcedatei f&uuml;r Spielsteine
 */

#include "Tile.h"

using namespace std;
//!< Einfacher Zugriff auf Funktionen der Standardbibliothek.
#include <list>							//!< Zur Erstelleung einer einfachern Liste
list < Block * > listBlock;				//!< Bl&ouml;cke f&uuml;r die Darstellung

Tile::Tile() :
			title( "KEIN NAMEN VORHANDEN" ),
			description( "KEINE BESCHREIBUNG VORHANDEN" ),
			rotation( 0 ),
			seal( false ),
			height( 0 ),
			width( 0 ),
			blockArray()
{

}

Tile::Tile( const char *_title , const char* _description ) :
			title( _title ),
			description( _description ),
			rotation( 0 ),
			seal( false ),
			height( 0 ),
			width( 0 ),
			blockArray()
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
			width( _width ),
			blockArray(new Block[_width * _height])
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
	delete[] blockArray; // TODO: Muss hier vorher jeder einzelne Block gelöscht werden?
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

void Tile::rotate()
{
	//blockArray transponieren
	Block* newArray = new Block[height * width];
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			newArray[y*width+x] = blockArray[x*height+y]; //dafuq am i doin'
		}
	}
	int temp = width;
	width = height;
	height = temp;
	delete[] blockArray;
	blockArray = new Block[width * height];
	//newArray spiegeln
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			blockArray[x*height+y] = newArray[(width-x-1)*height+(height-y-1)]; //<3 2D Arrays.
		}
	}
	//die Matrix sollte nicht ausgerichtet werden müssen, vorrausgesetzt width und height der alten Matrix waren minimal gesetzt, und
	// der Inhalt war bereits ausgerichtet

	return;
}


