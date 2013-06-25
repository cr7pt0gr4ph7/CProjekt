/*
 * @file	TileL.cpp
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileL.cpp
 */

#include "TileL.h"

TileL::TileL() :
	Tile("L", 1, 2, 3, createBaseArray())
{
}

TileL::TileL(const unsigned short _posX, const unsigned short _posY) :
		Tile("L", 1, 2, 3, _posX, _posY, createBaseArray())
{
}

TileL::~TileL()
{

}

// erzeugt eine Matrix der H�he 3 und Breite 2 die komplett mit der Basisform des Steins befuellt ist
char* TileL::createBaseArray() {
	width = 2;
	height = 3;
	char* result = new char[width * height];
	// (0|0) bis (1|0)
	result[0*height+0] = 'X';
	result[1*height+0] = ' ';
	// (0|1) bis (1|1)
	result[0*height+1] = 'X';
	result[1*height+1] = ' ';
	// (0|2) bis (1|2)
	result[0*height+2] = 'X';
	result[1*height+2] = 'X';

	return result;
}
