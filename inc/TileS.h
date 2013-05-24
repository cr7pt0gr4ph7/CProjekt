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

/**
 * Kindklasse f&uuml;r den Spielstein S
 */
class TileS : public Tile
{
	public:
		/*!
		 * \brief Konstrutor mit Standartwerten.
		 */
		TileS();
		/*!
		 * \brief Destruktor
		 */
		virtual ~TileS();
};

#endif /* TILES_H_ */
