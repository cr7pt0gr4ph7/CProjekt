/*!
 * @file	TileO.h
 *
 * @date	24.05.2013
 * @author	Superuser
 * @brief	Headerdatei f&uuml;r Spielstein O
 */

#ifndef TILEO_H_
#define TILEO_H_

#include "Tile.h"

/**
 * \brief Kindklasse f&uuml;r den Spielstein O
 */
class TileO : public Tile
{
	public:
		/*!
		 * \brief Konstrutor mit Standartwerten.
		 */
		TileO();
		/*!
		 * \brief Destruktor
		 */
		virtual ~TileO();
};

#endif /* TILEO_H_ */
