/*
 * @file	Console.cpp
 *
 * @date	21.05.2013
 * @author	Superuser
 * @brief	Console.cpp
 */

#ifdef _WIN32
#include <Windows.h>
#endif
#include <iostream>
#include "Startscr.h"
#include "winlin.h" //fuer Linux! -> winlin.cpp
#include <cstdio>

using namespace std;

Startscr::Startscr()
{
	// TODO Auto-generated constructor stub

}

Startscr::~Startscr()
{
	// TODO Auto-generated destructor stub
}

int Startscr::startscrPrintout()
{
	int Eingabe = 0;

	setWindow( 50 , 35 );

	newSystem("CLS");
	cout << "--------------------------------------------------" << endl;
	cout << "---------------------TETRIS-----------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "(1) Starten" << endl;
	cout << "(2) Anleitung" << endl;
	cout << "(3) Beenden" << endl;
	cout << "Bitte waehlen: "; cin >> Eingabe;
	while(getchar()!='\n');
	if ( Eingabe == 1 )
	{
		wait_ms(500);
		return 1;
	}
	if ( Eingabe == 2 )
	{
		cout << "Anleitung" << endl;
		instructionsPrintout( );
	}
	if ( Eingabe == 3 )
		return 0;

	// TODO: "Spiel" und "Anleitung" implementieren.
	return 0;
}

int Startscr::instructionsPrintout()
{
	newSystem("CLS");
	cout << endl << "== Verfuegbare Spielsteine ==" << endl << endl;

	cout << "[X ] - Der L-Baustein" << endl;
	cout << "[X ]" << endl;
	cout << "[XX]" << endl;

	cout << endl;

	cout << "[ X] - Der J-Baustein" << endl;
	cout << "[ X]" << endl;
	cout << "[XX]" << endl;

	cout << endl;

	cout << "[X ] - Der S-Baustein" << endl;
	cout << "[XX]" << endl;
	cout << "[ X]" << endl;

	cout << endl;

	cout << "[ X] - Der Z-Baustein" << endl;
	cout << "[XX]" << endl;
	cout << "[X ]" << endl;

	cout << endl;

	cout << "[ X] - Der T-Baustein" << endl;
	cout << "[XX]" << endl;
	cout << "[ X]" << endl;

	cout << endl;

	cout << "[XX] - Der O-Baustein" << endl;
	cout << "[XX]" << endl;

	cout << endl;

	cout << "[*]  - Der I-Baustein" << endl;
	cout << "[*]" << endl;
	cout << "[*]" << endl;
	cout << "[*]" << endl;

	cout << endl;

	newSystem("PAUSE");

	return 0;
}

void Startscr::setWindow( short pWidth, short pHeight )
{
#ifdef __unix__

#endif

#ifdef _WIN32
	hCon = GetStdHandle( STD_OUTPUT_HANDLE );
	SMALL_RECT size;
	COORD b_size;

	size.Left = 0;
	size.Top = 0;
	size.Right = pWidth;
	size.Bottom = pHeight;
	b_size.X = pWidth + 1;
	b_size.Y = pHeight + 1;

	SetConsoleWindowInfo( hCon , true , & size );
	SetConsoleScreenBufferSize( hCon , b_size );
#endif
}
