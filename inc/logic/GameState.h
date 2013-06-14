/*
 * GameState.h
 *
 *  Created on: 12.06.2013
 *      Author: Lukas Waslowski
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Spielfeld.h"

/**
 * @brief GameState ist ein Container f&uuml;r alle zur Beschreibung eines Spielzustandes n&ouml;tigen Werte
 *        (Spielfeld, Aktueller Stein mit Position etc, Punktzahl ...).
 */
class GameState
{
private:
	static const int DEFAULT_BOARD_WIDTH = 20;
	static const int DEFAULT_BOARD_HEIGHT = 25;

	static const int DEFAULT_FRAME_DURATION_MS = 1000 / 10;

private:
	/**
	 * @brief Das aktuelle Spielfeld.
	 */
	Spielfeld* spielfeld;

	/**
	 * @brief Die Länge eines einzelnen Frames (in Millisekunden).
	 */
	int frameDuration_ms;

public:
	GameState();
	virtual ~GameState();

	Spielfeld* getSpielfeld();
	int getFrameDuration();
};

#endif /* GAMESTATE_H_ */
