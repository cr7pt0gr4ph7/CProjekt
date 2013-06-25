#ifndef __SPIELFELD_H__
#define __SPIELFELD_H__

#include "Tile.h"
#include "TileI.h"
#include "TileL.h"
#include "TileO.h"
#include "TileS.h"
#include "TileT.h"

class Spielfeld{
private:
	int width;
	int height;
	int infoWidth;
	char *spielfeld;
	char *info;
	char *spielfeldinfo; //spielfeld + info
	Tile* activeTile;
	Tile* nextTile;
	int score;
	int lines;

	Block *board; //als Block fuer Uebergabe an Output
public:
	Spielfeld(int pWidth, int pHeight);
	int getWidth();
	int getHeight();
	int getInfoWidth();
	int getScore();
	int getLines();
	char* getSpielfeld();
	char* getSpielfeldinfo();
	Tile* getNextTile();
	Tile* getActiveTile();
	void initTiles();
	void setNextTile();
	void setActiveTile();
	Tile* randomTile();
	void clearSpielfeld(); //Spielfeld leeren
	void printSpielfeld(); //Spielfeld ausgeben
	void clearInfo(); //Info leeren
	void initInfo(); //Info initialisieren
	void addTextToInfo(const char* pStr, int pX, int pY); //Text an Punkt [X|Y] einfuegen
	void addIntToInfo(int pInt, int pX, int pY); //Integer an Punkt [X|Y] einfuegen
	void addInfoToSpielfeld(); //Info an Spielfeldhaengen
	void drawPoint(int pX, int pY); //Punkt im Spielfeld einfuegen
	int checkBottomCollision(); //überprüfe auf kollisionen
	int checkRightCollision();
	int checkLeftCollision();
	void getTiles();

	void clearBoard(); //Block Spielfeld leeren

	~Spielfeld();
};

#endif
