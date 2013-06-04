/*
 * @file	TileI.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileI.h
 */

#ifndef TILEI_H_
#define TILEI_H_

#include "Tile.h"

class TileI : public Tile
{
	public:
		TileI();
		TileI(const unsigned short _posX, const unsigned short _posY);
		virtual ~TileI();
	private:
		virtual Block** createBaseArray();
};

#endif /* TILEI_H_ */
