/*!
 * @file	TileI.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	Headerdatei f&uuml;r Spielstein I
 */

#ifndef TILEI_H_
#define TILEI_H_

#include "Tile.h"

/**
 * \brief Kindklasse f&uuml;r den Spielstein I
 */
class TileI : public Tile
{
	public:
		/*!
		 * \brief Konstrutor mit Standartwerten.
		 */
		TileI();
		/*!
		 * \brief Destruktor
		 */
		virtual ~TileI();
};

#endif /* TILEI_H_ */
