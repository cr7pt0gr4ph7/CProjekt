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
		gameState(new GameState()), renderer(new Output())
{
}

GameScreen::~GameScreen()
{
	// TODO Auto-generated destructor stub
}

void GameScreen::doLogic(void)
{
	// TODO Spiellogik implementieren bzw. in eigene Klasse auslagern
}

void GameScreen::run(void)
{
	clear_console_window();

	while (true)
	{
		doLogic();

		renderer->render(gameState);

		// TODO Die fuer die Spiellogik und das Rendern benoetigte Zeit abziehen
		wait_ms (gameState->getFrameDuration());
		//if(Kollision in oberster Reihe) break;
	}
	//Game Over
	wait_for_keypress();
}

