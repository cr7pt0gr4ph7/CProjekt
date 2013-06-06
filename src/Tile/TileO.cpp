/*
 * @file	TileO.cpp
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileO.cpp
 */

#include "TileO.h"

TileO::TileO():
	Tile("O", "4 Bloecke im Quadrat angeordnet.", 2, 2, createBaseArray())
{
}

TileO::TileO(const unsigned short _posX, const unsigned short _posY) :
		Tile("O", "4 Bloecke im Quadrat angeordnet.", 2, 2, _posX, _posY, createBaseArray())
{
}

TileO::~TileO()
{

}

// erzeugt eine Matrix der Höhe 2 und Breite 2 die komplett mit der Basisform des Steins befuellt ist
Block** TileO::createBaseArray() {
	width = 2;
	height = 2;
	Block** result = new Block*[width * height];
	// (0|0) bis (1|0)
	result[0*height+0] = new Block(true);
	result[1*height+0] = new Block(true);
	// (0|1) bis (1|1)
	result[0*height+1] = new Block(true);
	result[1*height+1] = new Block(true);

	return result;
}

