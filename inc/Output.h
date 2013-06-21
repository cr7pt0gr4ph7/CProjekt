/*
 * Output.h
 *
 *  Created on: 11.06.2013
 *      Author: mo
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "logic/GameState.h"

class Output {
private:
	GameState* game;

public:
	Output(GameState* pGameState);
	void render();
	~Output();
	void printGame();
	void setNextTile();
	void setScore();
	void drawTile(); // wenn Tiles als char Arrays gespeichert sind
};

#endif /* OUTPUT_H_ */
