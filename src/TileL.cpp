/*
 * @file	TileL.cpp
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileL.cpp
 */

#include "..\inc\TileL.h"

TileL::TileL() :
	Tile("L", "4 Bloecke L-foermig angeordnet.", 2, 3, createBaseArray())
{
}

TileL::TileL(const unsigned short _posX, const unsigned short _posY) :
		Tile("L", "4 Bloecke L-foermig angeordnet.", 2, 3, _posX, _posY, createBaseArray())
{
}

TileL::~TileL()
{

}

// erzeugt eine Matrix der Höhe 3 und Breite 2 die komplett mit der Basisform des Steins befuellt ist
Block** TileL::createBaseArray() {
	width = 2;
	height = 3;
	Block** result = new Block*[width * height];
	// (0|0) bis (1|0)
	result[0*height+0] = new Block(true);
	result[1*height+0] = new Block(false);
	// (0|1) bis (1|1)
	result[0*height+1] = new Block(true);
	result[1*height+1] = new Block(false);
	// (0|2) bis (1|2)
	result[0*height+2] = new Block(true);
	result[1*height+2] = new Block(true);

	return result;
}
