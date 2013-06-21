/*
 * @file	TileL.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileL.h
 */

#ifndef TILEL_H_
#define TILEL_H_

#include "Tile.h"

class TileL : public Tile
{
	public:
		TileL();
		TileL(const unsigned short _posX, const unsigned short _posY);
		virtual ~TileL();
	private:
		virtual char* createBaseArray();
};

#endif /* TILEL_H_ */
