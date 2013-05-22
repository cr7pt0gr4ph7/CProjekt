/*
 * Tile.h
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#ifndef TILE_H_
#define TILE_H_

class Tile
{
public:
	Tile();
	Tile(const char *_title, const char* _description);
	virtual ~Tile();
private:
	const char *title;			//!< Name des Bausteines
	const char *description;	//!< Beschreibung des Bausteienes
};

#endif /* TILE_H_ */
