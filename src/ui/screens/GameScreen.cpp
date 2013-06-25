/*
 * GameScreen.cpp
 *
 *  Created on: 12.06.2013
 *      Author: lw
 */

#include <iostream>
#include "winlin.h"
#include "ui/screens/GameScreen.h"
#include <cstdio>
#include <cstring>
#ifdef __WIN32
#include <conio.h>
#endif

using namespace std;


GameScreen::GameScreen() :
		gameState(new GameState()), renderer(new Output(gameState))
{
}

GameScreen::~GameScreen()
{
	// TODO Auto-generated destructor stub
}

int GameScreen::doLogic(void)
{
	// TODO Spiellogik implementieren bzw. in eigene Klasse auslagern

	Spielfeld* feld = gameState->getSpielfeld();
	if(kbhit())
		switch(getch())
		{
		case 97: // Taste A -> nach links
			if(feld->checkLeftCollision())
			{
				cout << "KOLLISION" << endl;
				if(feld->getActiveTile()->getPosY() == 1) return 1;
				feld->drawTile();
				feld->initTiles();
			}
			else
				feld->getActiveTile()->moveLeft();
			break;
		case 100: //Taste D -> nach rechts
			if(feld->checkRightCollision())
			{
				cout << "KOLLISION" << endl;
				if(feld->getActiveTile()->getPosY() == 1) return 1;
				feld->drawTile();
				feld->initTiles();
			}
			else
				feld->getActiveTile()->moveRight();
			break;
		case 119: //Taste W -> drehen
			feld->getActiveTile()->rotatecw();

		}
	if(feld->checkBottomCollision())
	{
		cout << "KOLLISION" << endl;
		if(feld->getActiveTile()->getPosY()==1) return 1;
		feld->drawTile();
		feld->initTiles();
	}
	else
		feld->getActiveTile()->moveDown();
	return 0;
}

void GameScreen::run(void)
{
	clear_console_window();

	while(true)
	{
		if(doLogic()) break;

		renderer->render();

		// TODO Die fuer die Spiellogik und das Rendern benoetigte Zeit abziehen
		wait_ms (gameState->getFrameDuration());
		//if(Kollision in oberster Reihe) break;
	}
	//Game Over
	wait_for_keypress();
}


