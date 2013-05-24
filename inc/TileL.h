/*!
 * @file	TileL.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	Headerdatei f&uuml;r Spielstein L
 */

#ifndef TILEL_H_
#define TILEL_H_

#include "Tile.h"

/**
 * \brief Kindklasse von Tile f&uuml;r den Spielstein L
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
