/*
 * GameScreen.h
 *
 *  Created on: 12.06.2013
 *      Author: lw
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include "Output.h"
#include "Spielfeld.h"
#include "ui/screens/Interface.h"

class GameScreen: public Interface
{
private:
	static const int DEFAULT_BOARD_WIDTH = 20;
	static const int DEFAULT_BOARD_HEIGHT = 25;

	static const int DEFAULT_FRAME_DURATION_MS = 1000 / 10;

private:
	/**
	 * @brief Eine Instanz von @see Output zum Ausgeben des aktuellen Spielfelds auf den Bildschirm.
	 */
	Output* renderer;

	/**
	 * @brief Das aktuelle Spielfeld.
	 */
	Spielfeld* spielfeld;

	/**
	 * @brief Die Länge eines einzelnen Frames (in Millisekunden).
	 */
	int frameDuration_ms;

public:
	GameScreen();
	virtual ~GameScreen();

	void run();

private:
	void doLogic();
};

#endif /* GAMESCREEN_H_ */
