/*
 * @file	TileS.cpp
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileS.cpp
 */

#include "TileS.h"

TileS::TileS():
	Tile("S", 3, 3, 2, createBaseArray())
{
}

TileS::TileS(const unsigned short _posX, const unsigned short _posY) :
		Tile("S", 3, 3, 2, _posX, _posY, createBaseArray())
{
}

TileS::~TileS()
{

}

// erzeugt eine Matrix der Höhe 2 und Breite 3 die komplett mit der Basisform des Steins befuellt ist
Block** TileS::createBaseArray() {
	width = 3;
	height = 2;
	Block** result = new Block*[width * height];
	// (0|0) bis (2|0)
	result[0*height+0] = new Block(false);
	result[1*height+0] = new Block(true);
	result[2*height+0] = new Block(true);
	// (0|1) bis (2|1)
	result[0*height+1] = new Block(true);
	result[1*height+1] = new Block(true);
	result[2*height+1] = new Block(false);

	return result;
}
