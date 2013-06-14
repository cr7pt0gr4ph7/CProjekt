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

public:
	Output();
	void render(GameState* pGameState);
	~Output();
};

#endif /* OUTPUT_H_ */
