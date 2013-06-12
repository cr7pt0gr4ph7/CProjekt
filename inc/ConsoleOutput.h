/*
 * ConsoleOutput.h
 *
 *  Created on: 11.06.2013
 *      Author: mo
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Spielfeld.h"

class ConsoleOutput {

public:
	ConsoleOutput();
	void render(Spielfeld* pSpielfeld);
	~ConsoleOutput();
};

#endif /* OUTPUT_H_ */
