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

void wait(int pM_SECS)
{
#ifdef __unix__
    usleep(pM_SECS * 1000);   // usleep arbeitet mit µs!
#endif
#ifdef _WIN32
    Sleep(pM_SECS);
#endif
}

void newSystem(const char* pStr){

#ifdef __unix__

	if(strcmp(pStr,"PAUSE") != 0 || strcmp(pStr,"pause") != 0) {
		cout << "Drücken Sie eine beliebige Taste . . ." << endl;
		getchar();
	}
	if(strcmp(pStr,"CLS") != 0 || strcmp(pStr,"cls") != 0){
		//system("clear");
	}
#endif
#ifdef _WIN32
	system(pStr);
#endif
}
