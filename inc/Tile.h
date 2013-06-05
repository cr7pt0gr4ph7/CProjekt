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
		unsigned short posX;			//!< Position des Bausteins auf der x-Achse
		unsigned short posY;			//!< Position des Bausteins auf der y-Achse
		void move(int dX, int dY);      //!< Verschiebt den Baustein um dX|dY
	protected:
		unsigned short rotation;//!< Rotation vom Baustein 0&deg;, 90&deg;, 180&deg;, 270&deg;, 360&deg;
		bool seal;						//!< Ist Baustein gespiegelt?
		unsigned short height;			//!< H&ouml;he des Bausteines
		unsigned short width;			//!< Breite des Bausteines
		Block ** blockArray;
		void transpose(Block** oldArray, int width, int height);
		void mirror(Block** oldArray, int width, int height);
		virtual Block** createBaseArray();
	public:
		// ###################################KONSTRUKTOREN#################################
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
		Tile( const char *_title, const char* _description);
		/*!
		 * \brief Konstrutor.
		 * Initialisierung eines Bausteines
		 * @param _title	Titel des Bausteins
		 * @param _description	Beschreibung des Bausteins
		 * @param _width	Breite des Bausteins
		 * @param _height	H&ouml;he des Bausteins
		 */
		Tile(const char *_title, const char* _description, const unsigned short _width, const unsigned short _height);
		/*!
		 * \brief Konstrutor.
		 * Initialisierung eines Bausteines
		 * @param _title	Titel des Bausteins
		 * @param _description	Beschreibung des Bausteins
		 * @param _width	Breite des Bausteins
		 * @param _height	H&ouml;he des Bausteins
		 * @param _blockArray Matrix des Bausteins
		 */
		Tile(const char *_title, const char* _description, const unsigned short _width, const unsigned short _height, Block** _blockArray);
		/*!
		 * \brief Konstrutor.
		 * Initialisierung eines Bausteines
		 * @param _title	Titel des Bausteins
		 * @param _description	Beschreibung des Bausteins
		 * @param _width	Breite des Bausteins
		 * @param _height	H&ouml;he des Bausteins
		 * @param _posX x-Position des Bausteins
		 * @param _posY y-Position des Bausteins
		 * @param _blockArray Matrix des Bausteins
		 */
		Tile(const char *_title, const char* _description, const unsigned short _width, const unsigned short _height, const unsigned short _posX, const unsigned short _posY, Block** _blockArray);
		/*!
		 * \brief Destruktor
		 */
		virtual ~Tile();

		// ###################################GETTER & SETTER###############################

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
		/*!
		 * Gibt zur&uuml;ck, ob der Baustein gespieglt ist
		 * @return TURE: Gespeigelt, FALSE: Nicht gespiegelt
		 */
		const bool getSeal() const
		{
			return seal;
		}
		/*!
		 * Gibt die H&ouml;he des Bausteins zur&uuml;ck;
		 * @return H&ouml;he des Bausteienes
		 */
		const unsigned short getHeight() const
		{
			return height;
		}
		/*!
		 * Gibt die Breite des Bausteins zur&uuml;ck;
		 * @return Breite des Bausteienes
		 */
		const unsigned short getWidth() const
		{
			return width;
		}
		/*!
		 * Gibt den x-Anteil der Position des Steines zurück.
		 * @return Position auf der x-Achse
		 */
		unsigned short getPosX() const {
			return posX;
		}
		/*!
		 * Setzt den x-Anteil der Position des Steines.
		 * @param Position auf der x-Achse
		 */
		void setPosX(unsigned short posX) {
			this->posX = posX;
		}
		/*!
		 * Gibt den y-Anteil der Position des Steines zurück
		 * @return Position auf der y-Achse
		 */
		unsigned short getPosY() const {
			return posY;
		}
		/*!
		 * Setzt den y-Anteil der Position des Steines.
		 * @param Position auf der y-Achse
		 */
		void setPosY(unsigned short posY) {
			this->posY = posY;
		}

		// ###################################FUNKTIONEN#####################################

		/*!
		 * Dreht den Block im Uhrzeigersinn
		 */
		void rotatecw(void);
		/*!
		 * Dreht den Block gegen den Uhrzeigersinn
		 */
		void rotateccw(void);
		/*!
		 * Gibt den Zeiger auf den Block an der Stelle (x|y) zurück.
		 * Hinweis: Wenn die Koordinaten (x|y) außerhalb der Grenzen der Steinmatrix liegen,
		 * so wird ein neues Blockobjekt erzeugt und der Zeiger hierauf zurück gegeben.
		 * @param x Position auf der x-Achse
		 * @param y Position auf der y-Achse
		 * @return Zeiger auf einen Block
		 */
		Block* getBlock(int x, int y) const;
		/*
		 * Bewegt den Stein nach links
		 */
		void moveLeft(void);
		/*
		 * Bewegt den Stein nach rechts
		 */
		void moveRight(void);
		/*
		 * Bewegt den Stein nach unten
		 */
		void moveDown(void);


};

#endif /* TILE_H_ */
