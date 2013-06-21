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

Output::Output()
{
	// TODO Auto-generated constructor stub
}

Output::~Output()
{
	// TODO Auto-generated destructor stub
}

void Output::render(GameState* pGameState)
{
	// TODO Aktuellen Stein auslesen
	// TODO Punktzahl auslesen
	// TODO Spielfeld ausgeben
	printGame(pGameState);


}
void Output::setNextTile(GameState* pGameState)
{


	switch(pGameState->getSpielfeld()->getNextTile()->getId())
	{
	case 0: 	pGameState->getSpielfeld()->addTextToInfo("  X ", 3,3);
				pGameState->getSpielfeld()->addTextToInfo("  X ", 3,4);
				pGameState->getSpielfeld()->addTextToInfo("  X ", 3,5);
				pGameState->getSpielfeld()->addTextToInfo("  X ", 3,6);
				break;

	case 1:	 	pGameState->getSpielfeld()->addTextToInfo("    ", 3,3);
				pGameState->getSpielfeld()->addTextToInfo(" X  ", 3,4);
				pGameState->getSpielfeld()->addTextToInfo(" X  ", 3,5);
				pGameState->getSpielfeld()->addTextToInfo(" XX ", 3,6);
				break;

	case 2:		pGameState->getSpielfeld()->addTextToInfo("    ", 3,3);
				pGameState->getSpielfeld()->addTextToInfo(" XX ", 3,4);
				pGameState->getSpielfeld()->addTextToInfo(" XX ", 3,5);
				pGameState->getSpielfeld()->addTextToInfo("    ", 3,6);
				break;

	case 3: 	pGameState->getSpielfeld()->addTextToInfo("    ", 3,3);
				pGameState->getSpielfeld()->addTextToInfo(" XX ", 3,4);
				pGameState->getSpielfeld()->addTextToInfo("XX  ", 3,5);
				pGameState->getSpielfeld()->addTextToInfo("   ", 3,6);
				break;

	case 4:		pGameState->getSpielfeld()->addTextToInfo(" X  ", 3,3);
				pGameState->getSpielfeld()->addTextToInfo(" XX ", 3,4);
				pGameState->getSpielfeld()->addTextToInfo(" X  ", 3,5);
				pGameState->getSpielfeld()->addTextToInfo("    ", 3,6);
				break;

	default:	cout<<"nextTile out of Bounds--->Output.cpp/SetNextTile or Spielfeld.cpp/nextTile"<<endl;
	}

}


void Output::setScore(GameState* pGameState)
{
	if(pGameState->getSpielfeld()->getScore()>0)
	{
		pGameState->getSpielfeld()->addTextToInfo( "" + pGameState->getSpielfeld()->getScore(),11,9);
	}
	else
		cout<<"ERROR!!! NEGATIVE SCORE ISNT POSSIBLE"<<endl;


	if(pGameState->getSpielfeld()->getLines()>0)
	{
		pGameState->getSpielfeld()->addTextToInfo( "" + pGameState->getSpielfeld()->getLines(),11,10);
	}
	else
		cout<<"NEGATIVE AMOUNT OF DONE LINES IS NONSENSE"<<endl;

}


void Output::printGame(GameState* pGameState)
{
	clear_console_window();
	setNextTile(pGameState);
	pGameState->getSpielfeld()->addInfoToSpielfeld();

		if(pGameState->getSpielfeld()->getHeight()>0 && pGameState->getSpielfeld()->getWidth()>0)
		{
			for(int y=0;y<pGameState->getSpielfeld()->getHeight();y++)
			{
				for(int x=0 ; x<(pGameState->getSpielfeld()->getInfoWidth()+pGameState->getSpielfeld()->getWidth()) ; x++)
				{
					char* buffer = pGameState->getSpielfeld()->getSpielfeldinfo();
					cout<< buffer[x*pGameState->getSpielfeld()->getHeight()+y];
				}
				cout<<endl;
			}
		}
		else
			cout<<"ERROR!!! WIDTH AND HEIGHT CANT BE NEGATIVE"<<endl;
		return;
}
