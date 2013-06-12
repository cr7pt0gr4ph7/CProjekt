/*
 * GameScreen.h
 *
 *  Created on: 12.06.2013
 *      Author: lw
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_

#include "ui/screens/Interface.h"

class GameScreen : public Interface {
public:
	GameScreen();
	virtual ~GameScreen();

	void run();
};

#endif /* GAMESCREEN_H_ */
