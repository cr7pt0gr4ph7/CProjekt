/*
 * Output.cpp
 *
 *  Created on: 11.06.2013
 *      Author: mo
 */

#include "Output.h"
#include "winlin.h"

Output::Output()
{
	// TODO Auto-generated constructor stub
}

Output::~Output()
{
	// TODO Auto-generated destructor stub
}

void Output::render(GameState* pGameState)
{
	// TODO Spielfeld ausgeben
	clear_console_window();
	pGameState->getSpielfeld()->printSpielfeldInfo();
	// TODO Aktuellen Stein ausgeben
	// TODO Punktzahl ausgeben
}
