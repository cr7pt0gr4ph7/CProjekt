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
	private:
		const char *title;			//!< Name des Bausteines
		const char *description;	//!< Beschreibung des Bausteienes
	protected:
		unsigned short rotation;	//!< Rotation vom Baustein 0&deg;, 90&deg;, 180&deg;, 270&deg;, 360&deg;
		bool seal;					//!< Ist Baustein gespiegelt?
		unsigned short height;		//!< H&ouml;he des Bausteines
		unsigned short width;		//!< Breite des Bausteines
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
};

#endif /* TILE_H_ */
