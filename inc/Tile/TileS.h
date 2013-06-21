/*
 * @file	TileS.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileS.h
 */

#ifndef TILES_H_
#define TILES_H_

#include "Tile.h"

class TileS : public Tile
{
	public:
		TileS();
		TileS(const unsigned short _posX, const unsigned short _posY);
		virtual ~TileS();
	private:
		virtual char* createBaseArray();
};

#endif /* TILES_H_ */
