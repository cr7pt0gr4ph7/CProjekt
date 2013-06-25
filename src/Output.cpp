/*
 * Output.cpp
 *
 *  Created on: 11.06.2013
 *      Author: mo
 */

#include "Output.h"
#include "winlin.h"
#include <iostream>
#include "Spielfeld.h"
#include <cstring>
using namespace std;

Output::Output(GameState* game) : game(game)
{
	// TODO Auto-generated constructor stub
}

Output::~Output()
{
	// TODO Auto-generated destructor stub
}

void Output::render()
{
	// TODO Aktuellen Stein auslesen
	// TODO Punktzahl auslesen
	// TODO Spielfeld ausgeben
	printGame();


}
void Output::setNextTile()
{

	if(game->getSpielfeld()->getNextTile() != nullptr)
	switch(game->getSpielfeld()->getNextTile()->getId())
	{
	case 0: 	game->getSpielfeld()->addTextToInfo("  X ", 3,3);
				game->getSpielfeld()->addTextToInfo("  X ", 3,4);
				game->getSpielfeld()->addTextToInfo("  X ", 3,5);
				game->getSpielfeld()->addTextToInfo("  X ", 3,6);
				break;

	case 1:	 	game->getSpielfeld()->addTextToInfo("    ", 3,3);
				game->getSpielfeld()->addTextToInfo(" X  ", 3,4);
				game->getSpielfeld()->addTextToInfo(" X  ", 3,5);
				game->getSpielfeld()->addTextToInfo(" XX ", 3,6);
				break;

	case 2:		game->getSpielfeld()->addTextToInfo("    ", 3,3);
				game->getSpielfeld()->addTextToInfo(" XX ", 3,4);
				game->getSpielfeld()->addTextToInfo(" XX ", 3,5);
				game->getSpielfeld()->addTextToInfo("    ", 3,6);
				break;

	case 3: 	game->getSpielfeld()->addTextToInfo("    ", 3,3);
				game->getSpielfeld()->addTextToInfo(" XX ", 3,4);
				game->getSpielfeld()->addTextToInfo("XX  ", 3,5);
				game->getSpielfeld()->addTextToInfo("   ", 3,6);
				break;

	case 4:		game->getSpielfeld()->addTextToInfo(" X  ", 3,3);
				game->getSpielfeld()->addTextToInfo(" XX ", 3,4);
				game->getSpielfeld()->addTextToInfo(" X  ", 3,5);
				game->getSpielfeld()->addTextToInfo("    ", 3,6);
				break;

	default:	cout<<"nextTile out of Bounds--->Output.cpp/SetNextTile or Spielfeld.cpp/nextTile"<<endl;
	}

	return;

}

void Output::setScore()
{
	if(game->getSpielfeld()->getScore()>=0)
	{
		game->getSpielfeld()->addIntToInfo(game->getSpielfeld()->getScore(),10,9);
	}
	else
		cout<<"ERROR!!! NEGATIVE SCORE ISNT POSSIBLE"<<endl;


	if(game->getSpielfeld()->getLines()>=0)
	{
		game->getSpielfeld()->addIntToInfo( game->getSpielfeld()->getLines(),10,10);
	}
	else
		cout<<"NEGATIVE AMOUNT OF DONE LINES IS NONSENSE"<<endl;

}

void Output::drawTile()
{
	Tile* teil = game->getSpielfeld()->getActiveTile();
	int posX = teil->getPosX();
	int posY = teil->getPosY();

	char* teilarray = teil->getBlockArray();

	cout << posX << "|" << posY << "|" << game->getSpielfeld()->getActiveTile()->getId() << endl;

	for(int y = posY; y<(posY + teil->getHeight()); y++ )
	{
		for(int x = posX; x<(posX + teil->getWidth()) ; x++)
		{
			game->getSpielfeld()->getSpielfeld()[x*game->getSpielfeld()->getHeight()+y] = teilarray[(x-posX)*teil->getHeight()+(y-posY)];
		}
	}

}

void Output::printGame()
{
	clear_console_window();
	game->getSpielfeld()->clearSpielfeld();
	setNextTile();
	setScore();
	drawTile();
	game->getSpielfeld()->addInfoToSpielfeld();

		if(game->getSpielfeld()->getHeight()>0 && game->getSpielfeld()->getWidth()>0)
		{
			for(int y=0;y<game->getSpielfeld()->getHeight();y++)
			{
				for(int x=0 ; x<(game->getSpielfeld()->getInfoWidth()+game->getSpielfeld()->getWidth()) ; x++)
				{
					char* buffer = game->getSpielfeld()->getSpielfeldinfo();
					cout<< buffer[x*game->getSpielfeld()->getHeight()+y];
				}
				cout<<endl;
			}
		}
		else
			cout<<"ERROR!!! WIDTH AND HEIGHT CANT BE NEGATIVE"<<endl;
		return;
}
