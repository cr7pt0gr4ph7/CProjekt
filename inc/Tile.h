/*
 * Tile.h
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#ifndef TILE_H_
#define TILE_H_

#include "Block.h"

class Tile
{
	private:
		const char *title;				//!< Name des Bausteines
		const char *description;		//!< Beschreibung des Bausteienes
	protected:
		unsigned short rotation;//!< Rotation vom Baustein 0&deg;, 90&deg;, 180&deg;, 270&deg;, 360&deg;
		bool seal;						//!< Ist Baustein gespiegelt?
		unsigned short height;			//!< H&ouml;he des Bausteines
		unsigned short width;			//!< Breite des Bausteines
	public:
		/*!
		 * \brief Konstrutor mit Standartwerten.
		 */
		Tile();
		/*!
		 * \brief Konstrutor.
		 * Initialisierung eines Bausteines
		 * @param _title	Titel des Bausteins
		 * @param _description	Beschreibung des Bausteins
		 */
		Tile( const char *_title , const char* _description );
		/*!
		 * \brief Konstrutor.
		 * Initialisierung eines Bausteines
		 * @param _title	Titel des Bausteins
		 * @param _description	Beschreibung des Bausteins
		 * @param _height	H&ouml;he des Bausteins
		 * @param _width	Breite des Bausteins
		 */
		Tile(
			const char *_title , const char* _description ,
			const unsigned short _height , const unsigned short _width );
		/*!
		 * \brief Destruktor
		 */
		virtual ~Tile();

		/*!
		 * Gibt den Titel des Bausteines zur&uuml;ck;
		 * @return Titel des Bausteienes
		 */
		const char* getTitle() const
		{
			return title;
		}
		/*!
		 * Gibt die Beschreibung des Bausteines zur&uuml;ck;
		 * @return Beschreibung des Bausteienes
		 */
		const char* getDescription() const
		{
			return title;
		}
		/*!
		 * Gibt die Rotation zur&uuml;ck;
		 * @return Raotation des Bausteienes
		 */
		const unsigned short getRotation() const
		{
			return rotation;
		}

		// weitere get Funktionen implementieren

		/*!
		 * Gibt den Zeiger auf einen Block zur&uuml;ck.
		 * @param _width Position auf der x-Achse (Breite)
		 * @param __height Postition auf der y-Achse (H&ouml;he)
		 * @return Zeiger auf einen Block.
		 */
		virtual Block *getPBlock(unsigned short _width, unsigned short _height);
		/*!
		 * Gibt einen Block zur&uuml;ck.
		 * @return Block.
		 */
		virtual Block getBlock(unsigned short _width, unsigned short _height);
};

#endif /* TILE_H_ */
