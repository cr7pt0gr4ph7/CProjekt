//============================================================================
// Name        : spielfeld.cpp
// Author      : Denis Gauss, Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : Spielbrett in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Spielfeld.h"
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;

Spielfeld::Spielfeld(int pWidth, int pHeight) :
						width(pWidth),
						height(pHeight),
						infoWidth(20),
						spielfeld(new char[pWidth*pHeight]),
						info(new char[infoWidth*pHeight]),
						spielfeldinfo(new char[(pWidth+infoWidth)*pHeight]),
						buffer(new char[(pWidth+infoWidth)*pHeight]),
						activeTile(nullptr),
						nextTile(nullptr),
						score(0),
						lines(0)
{
    clearSpielfeld();	//Leeres Spielfeld
    clearInfo(); 		//Leere Info
    clearBuffer();		//Leere Buffer
    initInfo();			//Initialisiere Info
    initTiles();
}

int Spielfeld::getWidth()
{
	return width;
}

int Spielfeld::getHeight()
{
	return height;
}

void Spielfeld::printSpielfeld()
{
	for(int y=0;y<height;y++)
	{
		for(int x=0 ; x<width ; x++)
		{
			cout<< spielfeld[x*height+y];
		}
		cout<<endl;
	}
	return;
}
void Spielfeld::drawPoint(int pX,int pY)
{
	spielfeld[pX*height+pY]='X';
	return;
}
void Spielfeld::clearSpielfeld()
{
	for(int y=0 ; y<height ; y++)//Spielfeld+Rand füllen
	{
		for(int x=0 ; x<width ; x++)
		{
			if((x==0 || x==width-1) || (y==0 || y==height-1))
			{
				spielfeld[x*height+y]='#';
			}
			else
			{
				spielfeld[x*height+y]=' ';
			}
		}
	}
	return;
}

void Spielfeld::clearBuffer()
{
	for(int y=0 ; y<height ; y++)//Spielfeld+Rand füllen
	{
		for(int x=0 ; x<(width+infoWidth) ; x++)
		{
			buffer[x*height+y]=' ';
		}
	}
	return;
}

void Spielfeld::clearInfo()
{
	for(int y=0;y<height;y++)
	{
		for(int x=0; x<width; x++)
		{
			info[x*height+y] = ' ';
		}
	}
	return;
}

void Spielfeld::setBuffer()
{
	//clearBuffer();
	bufferTile();
	buffer = spielfeldinfo;
}
char* Spielfeld::getBuffer()
{
	return buffer;
}

void Spielfeld::initInfo()
{
	addTextToInfo("Naechster Block:",1,1);
	addTextToInfo("oooo", 3,3);
	addTextToInfo("oooo", 3,4);
	addTextToInfo("oooo", 3,5);
	addTextToInfo("oooo", 3,6);
	addTextToInfo("Spielstand:", 1,8);
	addTextToInfo("Punkte ",3,9);
	addTextToInfo("Linien ",3,10);
	return;
}

void Spielfeld::addInfoToSpielfeld()
{
	for(int y=0;y<height;y++)
	{
		for(int x=0; x<(width+infoWidth); x++)
		{
			if(x<width) spielfeldinfo[x*height+y] = spielfeld[x*height+y];
			else spielfeldinfo[x*height+y] = info[(x-width)*height+y];
		}
	}
	return;
}

void Spielfeld::addTextToInfo(const char* pStr, int pX, int pY)
{
	for(unsigned int x=pX;x<=(pX+strlen(pStr));x++)
	{
		info[x*height+pY] = pStr[x-pX];
	}
	return;
}

void Spielfeld::addIntToInfo(int pInt, int pX, int pY)
{
	stringstream ss;
	ss << pInt;

	for(unsigned int x=pX;x<(pX+ss.str().size());x++)
	{
		info[x*height+pY] = ss.str()[x-pX];
	}

	return;
}

void Spielfeld::initTiles()
{
	if(nextTile!=nullptr)
	{
		activeTile = nextTile;
		setNextTile();
		return;
	}
	setActiveTile();
	setNextTile();
	return;
}

void Spielfeld::setActiveTile()
{
	activeTile = randomTile();
	return;
}

void Spielfeld::setNextTile()
{
	nextTile = randomTile();
	return;
}

Tile* Spielfeld::randomTile()
{
	int rand_ = rand() % 5;
	Tile* randTile;
	switch(rand_)
	{
	case 0:
		randTile = new TileI(5,1);
		break;
	case 1:
		randTile = new TileL(5,1);
		break;
	case 2:
		randTile = new TileO(5,1);
		break;
	case 3:
		randTile = new TileS(5,1);
		break;
	case 4:
		randTile = new TileT(5,1);
		break;
	}
	return randTile;
}

Tile* Spielfeld::getNextTile()
{
	return nextTile;
}

Tile* Spielfeld::getActiveTile()
{
	return activeTile;
}

int Spielfeld::getScore()
{
	return score;
}

int Spielfeld::getLines()
{
	return lines;
}

int Spielfeld::getInfoWidth()
{
	return infoWidth;
}

char* Spielfeld::getSpielfeld()
{
	return spielfeld;
}

char* Spielfeld::getSpielfeldinfo()
{
	return spielfeldinfo;
}

int Spielfeld::checkBottomCollision()
{
	for(int i = 0; i<activeTile->getWidth() ; i++)
		if(spielfeld[(activeTile->getPosX()+i)*height+(activeTile->getPosY()+activeTile->getHeight())]!=' ')
			return 1;
	return 0;
}

int Spielfeld::checkLeftCollision()
{
	for(int i = 0; i<activeTile->getHeight() ; i++)
		if(spielfeld[(activeTile->getPosX()-1)*height+(activeTile->getPosY()+activeTile->getHeight()+i)]!= ' ')
			return 1;
	return 0;
}

int Spielfeld::checkRightCollision()
{
	for(int i = 0; i<activeTile->getHeight() ; i++)
		if(spielfeld[(activeTile->getPosX()+activeTile->getWidth()+1)*height+(activeTile->getPosY()+activeTile->getHeight()+i)]!= ' ')
			return 1;
	return 0;
}

void Spielfeld::drawTile()
{
	int posX = activeTile->getPosX();
	int posY = activeTile->getPosY();

	for(int y = posY; y<(posY + activeTile->getHeight()); y++ )
	{
		for(int x = posX; x<(posX + activeTile->getWidth()) ; x++)
		{
			spielfeld[x*height+y] = activeTile->getBlockArray()[(x-posX)*height+(y-posY)];
		}
	}
}
void Spielfeld::bufferTile()
{
	int posX = activeTile->getPosX();
	int posY = activeTile->getPosY();
	cout << posX << " | " << posY <<  endl;
	cout << activeTile->getWidth() << " | " << activeTile->getHeight() << endl;
	for(int y = posY; y<(posY + activeTile->getHeight()); y++ )
	{
		for(int x = posX; x<(posX + activeTile->getWidth()) ; x++)
		{
			buffer[x*height+y] = activeTile->getBlockArray()[(x-posX)*height+(y-posY)];
		}
	}
	return;
}

Spielfeld::~Spielfeld()
{
	delete[] spielfeld;
	delete[] spielfeldinfo;
	delete[] info;
	delete activeTile;
	delete nextTile;
}
