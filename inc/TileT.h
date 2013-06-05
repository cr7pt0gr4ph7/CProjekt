/*
 * @file	TileT.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	TileT.h
 */

#ifndef TILET_H_
#define TILET_H_

#include "Tile.h"

class TileT : public Tile
{
	public:
		TileT();
		TileT(const unsigned short _posX, const unsigned short _posY);
		virtual ~TileT();
	private:
		virtual Block** createBaseArray();
};

#endif /* TILET_H_ */
