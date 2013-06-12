//============================================================================
// Name        : spielfeld.cpp
// Author      : Denis Gauss, Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : Spielbrett in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Spielfeld.h"
using namespace std;

Spielfeld::Spielfeld(int pWidth, int pHeight) : width(pWidth), height(pHeight), spielfeld(new char[pWidth*pHeight])
{
    clearSpielfeld();	//Leeres Spielfeld
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
	int x,y;
	for(x=0;x<width;x++)
	{
		for(y=0 ; y<height ; y++)
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
	int x,y;
	spielfeld = new char[width*height];

	for(x=0 ; x<width ; x++)//Spielfeld+Rand füllen
	{
		for(y=0 ; y<height ; y++)
		{
			if((x==0 || x==width-1) && (y!=0 || y!=height-1))
			{
				spielfeld[x*height+y]='#';
			}
			else if(y==0 || y==height-1)
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



Spielfeld::~Spielfeld()
{
	delete[] spielfeld;
}
