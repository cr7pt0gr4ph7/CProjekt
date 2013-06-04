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
using namespace std;

#include "Tile.h"
#include "Console.h"
#include <stdio.h>

// Durch das Entkommentieren der folgenden Flags lassen sich einige Debug-Meldungen aktivieren:
// #define DEBUG_GAME_STARTUP
// #define DEBUG_GAME_SHUTDOWN

/*!
 * @brief	Einstiegspunkt f&uuml;r das gesammte Projekt.
 * Hier werden die erste Schritte ausgef&uuml;rt und erlebt somit das Projekt zum leben.
 *
 * @param argc	Anzahl der Aufrufparameter.
 * @param argv	Pointer auf Aufrufparameter
 */
int main( int argc , char **argv )
{
#ifdef DEBUG_GAME_STARTUP
	// HINWEIS: Programmcode, der lediglich zum Debuggen des Spiels benötigt wird,
	//          sollte zwischen diesem Kommentar und dem "#endif" eingefügt werden.

	// Falls diese Ausgabe erscheint, so wissen wir zumindest,
	// dass das Program erfolgreich gestartet wurde:
	cout << "===========================================================" << endl;
	cout << "=      CProjekt                                           =" << endl;
	cout << "===========================================================" << endl;
#endif

	// Initialisieren der Benutzeroberfläche (in Form einer Textkonsole)
	Console* console = new Console( );

	// Benutzeroberfläche anzeigen
	console->oberflaeche( );

#ifdef DEBUG_GAME_SHUTDOWN
	cout << endl;
	system("PAUSE");
#endif

	// Aufräumcode:
	delete console;

#ifdef DEBUG_GAME_SHUTDOWN
	cout << "Das Programm wurde beendet." << endl;
#endif

	return 0;
}

