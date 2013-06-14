/*
 * GameState.cpp
 *
 *  Created on: 12.06.2013
 *      Author: Lukas Waslowski
 */

#include "logic/GameState.h"

GameState::GameState() :
		spielfeld(new Spielfeld(DEFAULT_BOARD_WIDTH, DEFAULT_BOARD_HEIGHT)), frameDuration_ms(
				DEFAULT_FRAME_DURATION_MS)
{
	// TODO Auto-generated constructor stub

}

GameState::~GameState()
{
	delete spielfeld;
}

Spielfeld* GameState::getSpielfeld(void)
{
	return this->spielfeld;
}

int GameState::getFrameDuration(void)
{
	return this->frameDuration_ms;
}
