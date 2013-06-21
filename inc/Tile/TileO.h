/*
 * @file	TileO.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileO.h
 */

#ifndef TILEO_H_
#define TILEO_H_

#include "Tile.h"

class TileO : public Tile
{
	public:
		TileO();
		TileO(const unsigned short _posX, const unsigned short _posY);
		virtual ~TileO();
	private:
		virtual char* createBaseArray();
};

#endif /* TILEO_H_ */
