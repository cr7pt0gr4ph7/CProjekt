/*
 * Tile.cpp
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#include "Tile.h"

/*!
 * Konstrutor mit Standartwerten
 */
Tile::Tile() :
			title( "KEIN NAMEN VORHANDEN" ),
			description( "KEINE BESCHREIBUNG VORHANDEN" )
{

}

/*!
 * Konstrutor
 * @param _title	Titel des Bausteins
 * @param _description	Beschreibung des Bausteins
 */
Tile::Tile( const char *_title , const char* _description ) :
			title( _title ),
			description( _description )
{

}

/*!
 * Destruktor
 */
Tile::~Tile()
{

}

