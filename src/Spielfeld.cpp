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
using namespace std;

Spielfeld::Spielfeld(int pWidth, int pHeight) : width(pWidth), height(pHeight), infoWidth(20), spielfeld(new char[pWidth*pHeight]), info(new char[infoWidth*pHeight]), spielfeldinfo(new char[(pWidth+infoWidth)*pHeight])
{
    clearSpielfeld();	//Leeres Spielfeld
    clearInfo(); 		//Leere Info
    initInfo();			//Initialisiere Info
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

void Spielfeld::initInfo()
{
	addTextToInfo("Naechster Block:",1,1);
	addTextToInfo("oooo", 3,3);
	addTextToInfo("oooo", 3,4);
	addTextToInfo("oooo", 3,5);
	addTextToInfo("oooo", 3,6);
	addTextToInfo("Spielstand:", 1,8);
	addTextToInfo("----- Punkte",3,9);
	addTextToInfo("  --- Linien",3,10);
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

int Spielfeld::getnextTile()
{
	return nextTile;
}

Spielfeld::~Spielfeld()
{
	delete[] spielfeld;
}
