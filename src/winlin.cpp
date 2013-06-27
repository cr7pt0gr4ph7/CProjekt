//============================================================================
// Name        : winlin.cpp
// Author      : Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : <windows.h> Abhaengigkeiten unter Linux aufgeloest, Ansi-style
//============================================================================

#ifdef __unix__
#include <unistd.h>
#include <X11/XKBlib.h>
#include <termios.h>
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

bool getKeyState(int vKey) {
#ifdef __unix__
	// UNIX-Systeme
	if(kbhit())
	{
		if(getch() == vKey) {
			return true;
		} else {
			return false;
		}
	}
#elif _WIN32
	// Windows-Systeme
	if(GetAsyncKeyState(vKey)) {
		return true;
	} else {
		return false;
	}
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

#ifdef __unix__
int kbhit(void) {
   struct termios term, oterm;

   int fd = 0;
   int c = 0;
   tcgetattr(fd, &oterm);
   memcpy(&term, &oterm, sizeof(term));

   term.c_lflag = term.c_lflag & (!ICANON);
   term.c_cc[VMIN] = 0;
   term.c_cc[VTIME] = 1;

   tcsetattr(fd, TCSANOW, &term);
   c = getchar();
   tcsetattr(fd, TCSANOW, &oterm);

   if (c != -1)
   ungetc(c, stdin);

   return ((c != -1) ? 1 : 0);
}

int getch()
{
   static int ch = -1, fd = 0;
   struct termios neu, alt;

   fd = fileno(stdin);
   tcgetattr(fd, &alt);

   neu = alt;
   neu.c_lflag &= ~(ICANON|ECHO);

   tcsetattr(fd, TCSANOW, &neu);
   ch = getchar();

   tcsetattr(fd, TCSANOW, &alt);
   return ch;
}
#endif

void clear_console_window(void)
{
#ifdef __unix__
	// UNIX-Systeme
	system("clear");
#elif _WIN32
	// Windows-Systeme
	system("CLS");
#endif
}
