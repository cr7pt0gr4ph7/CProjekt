/*
 * Tile.cpp
 *
 *  Created on: 21.05.2013
 *      Author: Superuser
 */

#include "Tile.h"
#include <stdlib.h>

using namespace std;



Tile::Tile(const char *_title, const unsigned short _id, const unsigned short _width, const unsigned short _height,	char* _blockArray) :
		title(_title), id(_id), posX(0), posY(0), height(_height), width(_width), blockArray(_blockArray)
{
	// Randomisierung der Startrotation und der Spiegelung des Spielsteins.
	randomize();
}

Tile::Tile(const char *_title, const unsigned short _id, const unsigned short _width, const unsigned short _height, const unsigned short _posX, const unsigned short _posY,	char* _blockArray) :
		title(_title), id(_id), posX(_posX), posY(_posY), height(_height), width(_width), blockArray(_blockArray)
{
	// Randomisierung der Startrotation und der Spiegelung des Spielsteins.
	randomize();
}

Tile::~Tile() {
	if(blockArray != nullptr) {
		delete[] blockArray; // TODO: Muss hier vorher jeder einzelne Block gel�scht werden?
	}
}

const char* Tile::getTitle() const
{
	return title;
}

const unsigned short Tile::getId() const
{
	return id;
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
	transpose();
	//width und height vertauschen
	int temp = width;
	width = height;
	height = temp;
	//newArray spiegeln
	mirror();
	//die Matrix sollte nicht ausgerichtet werden m�ssen, vorrausgesetzt width und height der alten Matrix waren minimal gesetzt, und
	// der Inhalt war bereits ausgerichtet
	return;
}

/*
 * Rotiert blockArray GUZS (CCW)
 */
void Tile::rotateccw() {
	//blockArray spiegeln
	mirror();
	//bloackArray transponieren
	transpose();
	//width und height vertauschen
	int temp = width;
	width = height;
	height = temp;

	return;
}

/*
 * Transponiert das 2D Block Array der Form Block[width * height]
 */
void Tile::transpose() {
	char* newArray = new char[height * width];
	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			newArray[y * width + x] = blockArray[x * height + y]; //dafuq am i doin'
		}
	}
	blockArray = newArray;
	return;
}

/*
 * Spiegelt das 2D Block Array der Form Block[width * height] vertikal.
 */
void Tile::mirror() {
	char* newArray = new char[width * height];
	for (int y = 0; y < height; ++y) {
		for (int x = 0; x < width; ++x) {
			newArray[x * height + y] = blockArray[(width - x - 1) * height + y]; //<3 2D Arrays.
		}
	}
	blockArray = newArray;
	return;
}

Block* Tile::getBlock(int x, int y) const {
	if (x >= width || y >= height || x < 0 || y < 0) {
		return new Block(false);
	}
	//return blockArray[x * height + y];
	return new Block(false);
}

char* Tile::createBaseArray() {
	// TODO: Das sieht nicht gesund aus
	return new char[width * height];
}

void Tile::moveLeft(void) {
	move(-1,0);
}

void Tile::moveRight(void) {
	move(1,0);
}

void Tile::moveDown(void) {
	move(0,1);
}

void Tile::move(int dX, int dY) {
	posX += dX;
	posY += dY;
	//TODO: evtl m�ssen hier noch die Bl�cke bewegt werden.
}

void Tile::randomize(void) {
	int m = rand() % 4;
	for (int n = 0; n < m; ++n) {
		rotatecw();
	}
	m = rand() % 2;
	for (int n = 0; n < m; ++n) {
		mirror();
	}
	return;
}

char* Tile::getBlockArray()
{
	return blockArray;
}
