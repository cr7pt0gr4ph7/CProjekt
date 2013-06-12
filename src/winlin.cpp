//============================================================================
// Name        : winlin.cpp
// Author      : Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : <windows.h> Abhaengigkeiten unter Linux aufgeloest, Ansi-style
//============================================================================

#ifdef __unix__
#include <unistd.h>
#endif
#ifdef _WIN32
#include <windows.h>
#endif
#include "winlin.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

void wait_ms(int pMS)
{
#ifdef __unix__
    usleep(pMS * 1000);   // usleep arbeitet mit µs!
#endif
#ifdef _WIN32
    Sleep(pMS);
#endif
}

void newSystem(const char* pStr)
{
#ifdef __unix__
	if(strcmp(pStr,"PAUSE") == 0 || strcmp(pStr,"pause") == 0)
	{
		wait_for_keypress();
	}
	else if(strcmp(pStr,"CLS") == 0 || strcmp(pStr,"cls") == 0)
	{
		clear_console_window();
	}
#elif _WIN32
	system(pStr);
#endif
}

void wait_for_keypress(void)
{
#ifdef __unix__
	// UNIX-System (inkl. Linux):
	//    Eigene Implementierung fuer "PAUSE" benutzen.

	cout << "Drücken Sie eine beliebige Taste . . ." << endl;
	getchar();
#elif _WIN32
	// Windows:
	//     Systemprogramm "PAUSE" verwenden.

	system("PAUSE");
#endif
}

void clear_console_window(void)
{
#ifdef __unix__
	// UNIX-Systeme
	system("CLEAR");
#elif _WIN32
	// Windows-Systeme
	system("CLS");
#endif
}
