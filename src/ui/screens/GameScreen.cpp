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
		renderer(new Output()), spielfeld(
				new Spielfeld(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT)), frameDuration_ms(
				DEFAULT_FRAME_DURATION_MS)
{
}

GameScreen::~GameScreen()
{
	// TODO Auto-generated destructor stub
}

void GameScreen::doLogic(void)
{
	// TODO Spiellogik implementieren
}

void GameScreen::run(void)
{
	clear_console_window();

	while (true)
	{
		doLogic();

		renderer->render(spielfeld);

		// TODO Die fuer die Spiellogik und das Rendern benoetigte Zeit abziehen
		wait_ms(frameDuration_ms);
	}

	wait_for_keypress();
}

