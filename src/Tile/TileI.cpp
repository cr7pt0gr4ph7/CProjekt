/*
 * @file	TileI.cpp
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileI.cpp
 */

#include "TileI.h"

TileI::TileI() :
		Tile("I", 0, 1, 4, createBaseArray())
{
}

TileI::TileI(const unsigned short _posX, const unsigned short _posY) :
		Tile("I", 0, 1, 4, _posX, _posY, createBaseArray())
{
}

TileI::~TileI()
{
}


// erzeugt eine Matrix der H�he 4 und Breite 1 die komplett mit der Basisform des Steins befuellt ist
char* TileI::createBaseArray() {
	unsigned short width = 1;
	unsigned short height = 4;
	char* result = new char[width * height];
	for (int y = 0; y < height; ++y) {
		result[0*height+y] = 'X';
	}
	return result;
}

