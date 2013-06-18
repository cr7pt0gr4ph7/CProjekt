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


}
void Output::setNextTile(GameState* pGameState)
{
	switch(pGameState->getSpielfeld()->nextTile)
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
	pGameState->getSpielfeld()->addTextToInfo("Spielstand: " +pGameState->getSpielfeld()->score ,1,8);
}


void Output::printGame(GameState* pGameState)
{
	clear_console_window();
	setNextTile(pGameState);
	pGameState->getSpielfeld()->addInfoToSpielfeld();

		for(int y=0;y<pGameState->getSpielfeld()->height;y++)
		{
			for(int x=0 ; x<(pGameState->getSpielfeld()->infoWidth+pGameState->getSpielfeld()->width) ; x++)
			{
				cout<< pGameState->getSpielfeld()->spielfeldinfo[x*pGameState->getSpielfeld()->height+y];
			}
			cout<<endl;
		}
		return;
}
