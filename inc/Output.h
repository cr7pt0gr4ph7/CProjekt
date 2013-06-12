/*
 * Output.h
 *
 *  Created on: 11.06.2013
 *      Author: mo
 */

#ifndef OUTPUT_H_
#define OUTPUT_H_

#include "Spielfeld.h"

class Output {

public:
	Output();
	void render(Spielfeld* pSpielfeld);
	~Output();
};

#endif /* OUTPUT_H_ */
