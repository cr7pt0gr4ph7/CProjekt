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
		const char *title;				//!< Name des Bausteins
		const unsigned short id;				//!< ID des Bausteins
		unsigned short posX;			//!< Position des Bausteins auf der x-Achse
		unsigned short posY;			//!< Position des Bausteins auf der y-Achse
		void move(int dX, int dY);      //!< Verschiebt den Baustein um dX|dY
		void randomize(void);			//!< Randomisiert Rotation und Spiegelung
	protected:
		unsigned short height;			//!< H&ouml;he des Bausteines
		unsigned short width;			//!< Breite des Bausteines
		Block ** blockArray;
		void transpose();
		void mirror();
		virtual Block** createBaseArray() = 0;
	public:
		Tile(const char *_title, const unsigned short _id, const unsigned short _width, const unsigned short _height, Block** _blockArray);
		Tile(const char *_title, const unsigned short _id, const unsigned short _width, const unsigned short _height, const unsigned short _posX, const unsigned short _posY, Block** _blockArray);

		virtual ~Tile();

		const char* getTitle() const;
		const unsigned short getId() const;
		const unsigned short getHeight() const;
		const unsigned short getWidth() const;
		unsigned short getPosX() const;
		void setPosX(unsigned short posX);
		unsigned short getPosY() const;
		void setPosY(unsigned short posY);

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
