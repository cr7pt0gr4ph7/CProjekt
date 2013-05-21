/*
 * Tile.cpp
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#include "Tile.h"

Tile::Tile():
		name("KEIN NAMEN VORHANDEN"),
		description("KEINE BESCHREIBUNG VORHANDEN")
{
	// TODO Auto-generated constructor stub

}

Tile::Tile(char *_name, char* _description):
		name(_name),
		description(_description)
{

}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

