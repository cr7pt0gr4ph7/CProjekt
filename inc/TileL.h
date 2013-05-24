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

/**
 * Kindklasse f&uuml;r den Spielstein L
 */
class TileL : public Tile
{
	public:
		/*!
		 * \brief Konstrutor mit Standartwerten.
		 */
		TileL();
		/*!
		 * \brief Destruktor
		 */
		virtual ~TileL();
};

#endif /* TILEL_H_ */
