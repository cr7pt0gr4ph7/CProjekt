//============================================================================
// Name        : winlin.cpp
// Author      : Maurice Angermann
// Version     : 1.0.0
// Copyright   : 2013, DHBW Karlsruhe
// Description : <windows.h> Abhaengigkeiten unter Linux aufgeloest, Ansi-style
//============================================================================

#ifndef __WINLIN_H__
#define __WINLIN_H__

void wait_ms(int pMS); //Sleep();
void newSystem(const char* pStr); //system();

void wait_for_keypress(); //!< system("PAUSE") (Win32) bzw. eigene Implementierung (Linux)
void clear_console_window(); //!< system("CLS") (Win32) bzw. system("CLEAR") (Linux)
bool getKeyState(int vKey); //!< GetAsyncKeyState(int vKey) (�bersetzt intern die Linuxkeycodes in Windows)
#ifdef __unix__
int getch();
int kbhit();
#endif

#endif
