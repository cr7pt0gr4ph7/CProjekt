/*
 * @file	TileT.cpp
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileT.cpp
 */

#include "TileT.h"
#include <iostream>

TileT::TileT() :
		Tile("T", 4, 3, 2, createBaseArray())
{
}

TileT::TileT(const unsigned short _posX, const unsigned short _posY) :
		Tile("T", 4, 3, 2, _posX, _posY, createBaseArray())
{
}

TileT::~TileT()
{

}

// erzeugt eine Matrix der Höhe 2 und Breite 3 die komplett mit der Basisform des Steins befuellt ist
Block** TileT::createBaseArray() {
	width = 3;
	height = 2;
	Block** result = new Block*[width * height];
	// (0|0) bis (2|0)
	result[0*height+0] = new Block(true);
	result[1*height+0] = new Block(true);
	result[2*height+0] = new Block(true);
	// (0|1) bis (2|1)
	result[0*height+1] = new Block(false);
	result[1*height+1] = new Block(true);
	result[2*height+1] = new Block(false);

	return result;
}
