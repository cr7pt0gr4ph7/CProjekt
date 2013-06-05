//============================================================================
// Name        : winlin.cpp
// Author      : Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : <windows.h> Abhängigkeiten unter Linux aufgelöst, Ansi-style
//============================================================================

#ifdef LINUX
#include <unistd.h>
#endif
#ifdef WINDOWS
#include <windows.h>
#endif
#include "../inc/winlin.h"
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void wait(int pM_SECS)
{
#ifdef LINUX
    usleep(pM_SECS * 1000);   // usleep arbeitet mit µs!
#endif
#ifdef WINDOWS
    Sleep(pM_SECS);
#endif
}

void newSystem(char* pStr){
#ifdef LINUX
	if(strcmp(pStr,"PAUSE") != 0 || strcmp(pStr,"pause") != 0) {
		cout << "Drücken Sie eine beliebige Taste . . ." << endl;
		getchar();
	}
#endif
#ifdef WINDOWS
	system(pStr);
#endif
}
