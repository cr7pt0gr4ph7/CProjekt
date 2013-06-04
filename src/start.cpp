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
#include "../inc/tcp.h"
using namespace std;

/*!
 * @brief	Einstiegspunkt f&uuml;r das gesamte Projekt.
 * Hier werden die ersten Schritte ausgef&uuml;hrt und erwecken somit das Projekt zum Leben.
 *
 * @param argc	Anzahl der Aufrufparameter
 * @param argv	Pointer auf Aufrufparameter
 */
int main(int argc, char **argv)
{
	cout << "===========================================================" << endl;
	cout << "=      CProjekt                                           =" << endl;
	cout << "===========================================================" << endl;
	tcp_main();
	return 0;
}

