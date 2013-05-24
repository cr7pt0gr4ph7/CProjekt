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

/**
 * Kindklasse f&uuml;r den Spielstein T
 */
class TileT : public Tile
{
	public:
		/*!
		 * \brief Konstrutor mit Standartwerten.
		 */
		TileT();
		/*!
		 * \brief Destruktor
		 */
		virtual ~TileT();
};

#endif /* TILET_H_ */
