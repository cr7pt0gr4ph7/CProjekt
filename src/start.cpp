/*!
 * @mainpage CProjekt
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
 * Die Dokumentation zu diesem Projekt wird mit [Doxygen](http://www.doxygen.org) und [Graphviz](http://www.graphviz.org) automatisch generiert.
 *
 * Eine gute Einf&uuml;hrung in Doxygen ist beispielsweise [hier](http://www2.informatik.hu-berlin.de/swt/projekt98/werkzeuge/doxygen/Doxygen.html#tth_chAp4) zu finden.
 *
 * Allen &ouml;ffentlichen Methoden und Attribute sollen so beschrieben werden, dass sich die Benutzung der Klasse alleine anhand der Dokumentation erschlie&szlig;t. Aus diesem Grunde sollten auch die von einer Methode erwarteten &Uuml;bergabeparameter sowie deren R&uuml;ckgabeewerte ausreichend detailliert beschrieben werden.
 *
 * Eine klare und saubere Dokumentation vereinfacht in allen F&auml;llen die Zusammenarbeit im Team wesentlich.
 *
 *
 * @section graph Aufbau
 * \dot
 * digraph Aufbau {
 * main -> Interface -> Console;
 * main -> Tile;
 * Tile -> TileI;
 * Tile -> TileL;
 * Tile -> TileO;
 * Tile -> TileS;
 * Tile -> TileT;
 * Tile -> Block
 * Interface -> Block
 * Interface -> Gameboard
 * }
 * \enddot
 * Strucktur des Projektes
 */

/*!
 * @file	start.cpp
 * @date	21.05.2013
 * @author	MS
 *
 * @brief	Keine Klasse, sondern f&uuml;r den Start notwendig.
 *
 */

#include <stdlib.h>
#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include "Spielfeld.h"
#include "winlin.h"
#include "ui/screens/Startscr.h"
#include "ConsoleOutput.h"

using namespace std;

/*
 * Funktion um das Programm zu intialisieren.
 * Bei Fehlern wird eine Exception geworfen.
 */
void init(void);

/*!
 * @brief	Einstiegspunkt fuer das gesamte Projekt.
 * Hier werden die ersten Schritte ausgefuehrt und erwecken somit das Projekt zum Leben.
 *
 * @param argc	Anzahl der Aufrufparameter
 * @param argv	Pointer auf Aufrufparameter
 */
int main(int argc, char* argv[])
{
	init();

	Startscr* startscreen = new Startscr();
	//Spielfeld* spiel = new Spielfeld(20,25);
	//Output* renderman = new Output();

	cout << "===========================================================" << endl;
	cout << "=      CProjekt                                           =" << endl;
	cout << "===========================================================" << endl;

	wait_ms(1000);

	if(startscreen->startscrPrintout())
	{
		clear_console_window();
		cout << "HIER WIRD IN KUERZE DAS SPIEL GESTARTET" << endl;
		wait_for_keypress();
	}

	return 0;
}

void init(void)
{
	// Zufallsgenerator initalisieren.
	srand(time(NULL));
}


