/*
 * GameScreen.h
 *
 *  Created on: 12.06.2013
 *      Author: lw
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include "Output.h"
#include "logic/GameState.h"
#include "ui/screens/Interface.h"

class GameScreen: public Interface
{
private:
	/**
	 * @brief GameState ist ein Container f&uuml;r alle zur Beschreibung eines Spielzustandes n&ouml;tigen Werte (Spielfeld, Aktueller Stein mit Position etc, Punktzahl ...).
	 */
	GameState* gameState;

	/**
	 * @brief Eine Instanz von @see Output zum Ausgeben des aktuellen Spielzustandes auf den Bildschirm.
	 */
	Output* renderer;


public:
	GameScreen();
	virtual ~GameScreen();

	void run();

private:
	int doLogic(); //return = 1 wenn gameover
};

#endif /* GAMESCREEN_H_ */
