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

// erzeugt eine Matrix der H�he 2 und Breite 3 die komplett mit der Basisform des Steins befuellt ist
char* TileT::createBaseArray() {
	width = 3;
	height = 2;
	char* result = new char[width * height];
	// (0|0) bis (2|0)
	result[0*height+0] = 'X';
	result[1*height+0] = 'X';
	result[2*height+0] = 'X';
	// (0|1) bis (2|1)
	result[0*height+1] = ' ';
	result[1*height+1] = 'X';
	result[2*height+1] = ' ';

	return result;
}
