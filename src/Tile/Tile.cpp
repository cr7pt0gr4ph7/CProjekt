/*
 * Tile.cpp
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#include "Tile.h"
#include <stdlib.h>

using namespace std;



Tile::Tile(const char *_title, const char* _description, const unsigned short _width, const unsigned short _height,	Block** _blockArray) :
		title(_title), description(_description), posX(0), posY(0), height(_height), width(_width), blockArray(_blockArray)
{
	// Randomisierung der Startrotation und der Spiegelung des Spielsteins.
	randomize();
}

Tile::Tile(const char *_title, const char* _description, const unsigned short _width, const unsigned short _height, const unsigned short _posX, const unsigned short _posY,	Block** _blockArray) :
		title(_title), description(_description), posX(_posX), posY(_posY), height(_height), width(_width), blockArray(_blockArray)
{
	// Randomisierung der Startrotation und der Spiegelung des Spielsteins.
	randomize();
}

Tile::~Tile() {
	if(blockArray != nullptr) {
		delete[] blockArray; // TODO: Muss hier vorher jeder einzelne Block gelöscht werden?
	}
}

const char* Tile::getTitle() const
{
	return title;
}

const char* Tile::getDescription() const
{
	return title;
}

const unsigned short Tile::getHeight() const
{
	return height;
}

const unsigned short Tile::getWidth() const
{
	return width;
}

unsigned short Tile::getPosX() const {
	return posX;
}

void Tile::setPosX(unsigned short posX) {
	this->posX = posX;
}

unsigned short Tile::getPosY() const {
	return posY;
}

void Tile::setPosY(unsigned short posY) {
	this->posY = posY;
}

/*
 * Rotiert blockArray im UZS (CW)
 */
void Tile::rotatecw() {
	//blockArray transponieren
	transpose(blockArray, width, height);
	//width und height vertauschen
	int temp = width;
	width = height;
	height = temp;
	//newArray spiegeln
	mirror(blockArray, width, height);
	//die Matrix sollte nicht ausgerichtet werden müssen, vorrausgesetzt width und height der alten Matrix waren minimal gesetzt, und
	// der Inhalt war bereits ausgerichtet
	return;
}

/*
 * Rotiert blockArray GUZS (CCW)
 */
void Tile::rotateccw() {
	//blockArray spiegeln
	mirror(blockArray, width, height);
	//bloackArray transponieren
	transpose(blockArray, width, height);
	//width und height vertauschen
	int temp = width;
	width = height;
	height = temp;

	return;
}

/*
 * Transponiert ein 2D Block Array der Form Block[width * height]
 */
void Tile::transpose(Block** oldArray, int width, int height) {
	Block** newArray = new Block*[height * width];
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			newArray[y * width + x] = oldArray[x * height + y]; //dafuq am i doin'
		}
	}
	blockArray = newArray;
	return;
}

/*
 * Spiegelt ein 2D Block Array der Form Block[width * height] vertikal.
 */
void Tile::mirror(Block** oldArray, int width, int height) {
	Block** newArray = new Block*[width * height];
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			newArray[x * height + y] = oldArray[(width - x - 1) * height + y]; //<3 2D Arrays.
		}
	}
	blockArray = newArray;
	return;
}

Block* Tile::getBlock(int x, int y) const {
	if (x >= width || y >= height || x < 0 || y < 0) {
		return new Block(false);
	}
	return blockArray[x * height + y];
}

Block** Tile::createBaseArray() {
	// TODO: Das sieht nicht gesund aus
	return new Block*[width * height];
}

void Tile::moveLeft(void) {
	move(-1,0);
}

void Tile::moveRight(void) {
	move(1,0);
}

void Tile::moveDown(void) {
	move(0,-1);
}

void Tile::move(int dX, int dY) {
	posX += dX;
	posY += dY;
	//TODO: evtl müssen hier noch die Blöcke bewegt werden.
}

void Tile::randomize(void) {
	int m = rand() % 4;
	for (int n = 0; n < m; ++n) {
		rotatecw();
	}
	m = rand() % 2;
	for (int n = 0; n < m; ++n) {
		mirror(blockArray, width, height);
	}
	return;
}

