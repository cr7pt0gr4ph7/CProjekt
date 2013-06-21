/*
 * GameScreen.cpp
 *
 *  Created on: 12.06.2013
 *      Author: lw
 */

#include <iostream>
#include "winlin.h"
#include "ui/screens/GameScreen.h"

using namespace std;

GameScreen::GameScreen() :
		gameState(new GameState()), renderer(new Output(gameState))
{
}

GameScreen::~GameScreen()
{
	// TODO Auto-generated destructor stub
}

void GameScreen::doLogic(void)
{
	// TODO Spiellogik implementieren bzw. in eigene Klasse auslagern
	/*if(false) // tastendruck rechts
	{
		gameState->getSpielfeld()->getActiveTile()->moveRight();
	}
	if(false) // tastendruck links
	{
		gameState->getSpielfeld()->getActiveTile()->moveLeft();

	}
	if(false) // tastendruck oben -> spielstein im uhrzeigersinn drehen
	{
		gameState->getSpielfeld()->getActiveTile()->rotatecw();
	}
	if(false) // tastendruck unten -> spielstein sofort nach unten
	{
	}

	//Spielstein immer eins nach unten
	gameState->getSpielfeld()->getActiveTile()->moveDown();*/
	renderer->moveDown();
}

void GameScreen::run(void)
{
	clear_console_window();

	while (true)
	{
		doLogic();

		renderer->render();

		// TODO Die fuer die Spiellogik und das Rendern benoetigte Zeit abziehen
		wait_ms (gameState->getFrameDuration());
		//if(Kollision in oberster Reihe) break;
	}
	//Game Over
	wait_for_keypress();
}

