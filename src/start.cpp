/*!
 * @mainpage C-Projekt
 *
 * @author DHBW Karslruhe TINF12B5 Gruppe 2
 *
 * @section sec1 Ziel des Projektes
 * Lernen der Programmiersprache C++.
 *
 * @subsection sec1_1 Vorsaussetzung
 * Grundlagen in C.
 *
 * @section doku Dokumentation
 * Dokumentation wird mithilfe von Doxygen automatisch erstellt. Bitte die Dokumentation von Doxygen f&uuml;r die Kommentare beachten und auch verwenden.
 */




/*!
 * @file	start.cpp
 * @date	21.05.2013
 * @author	Marcel Sutter
 *
 * @brief	Keine Klasse, sondern f&uuml;r den Start notwendig.
 *
 */

#include <stdlib.h>
#include <iostream>
using namespace std;

#include "Tile.h"
#include "TileI.h"
#include "TileO.h"
#include "TileT.h"
#include "TileL.h"
#include "TileS.h"

#include "Block.h"

#include <stdio.h>

void printTile(Tile * tile);

/*!
 * @brief	Einstiegspunkt f&uuml;r das gesammte Projekt.
 * Hier werden die erste Schritte ausgef&uuml;rt und erlebt somit das Projekt zum leben.
 *
 * @param argc	Anzahl der Aufrufparameter.
 * @param argv	Pointer auf Aufrufparameter
 */
int main(int argc, char **argv)
{
	cout << "===========================================================" << endl;
	cout << "=      CProjekt                                           =" << endl;
	cout << "===========================================================" << endl;

	Tile *pTile = new TileS();

	printf("%s - Hoehe: %i, Breite: %i", pTile->getTitle(), pTile->getHeight(), pTile->getWidth());

	cout << endl << endl;
	cout << "~~~~~~~~~~~ Drucke Stein ~~~~~~~~~~~" << endl;
	printTile(pTile);
	cout << endl;
	cout << "~~~~~~~~~~~ ############ ~~~~~~~~~~~" << endl;

	cout << endl << "rotiere Stein..." << endl;
	pTile->rotatecw();
	cout << "neue Hoehe: " << pTile->getHeight() << " , Breite: " << pTile->getWidth() << endl;

	cout << endl << endl;
	cout << "~~~~~~~~~~~ Drucke Stein ~~~~~~~~~~~" << endl;
	printTile(pTile);
	cout << endl;
	cout << "~~~~~~~~~~~ ############ ~~~~~~~~~~~" << endl;
//	system("PAUSE");
	delete(pTile);
	return 0;
}

void printTile(Tile * tile) {
	for (int y = 0; y < 5; ++y) {
		for (int x = 0; x < 5; ++x) {
			if (tile->getBlock(x,y)->isRendered()) {
				cout << "X";
			} else {
				cout << " ";
				delete tile->getBlock(x,y);
			}
		}
		cout << endl;
	}
}

