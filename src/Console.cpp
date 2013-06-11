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
#include "Console.h"
#include "winlin.h" //fuer Linux! -> winlin.cpp

using namespace std;

Console::Console()
{
	// TODO Auto-generated constructor stub

}

Console::~Console()
{
	// TODO Auto-generated destructor stub
}

int Console::oberflaeche()
{
	int Eingabe = 0;

	set_console( 50 , 35 );

	cout << "--------------------------------------------------" << endl;
	cout << "---------------------TETRIS-----------------------" << endl;
	cout << "--------------------------------------------------" << endl;
	cout << "\n(1) Starten" << endl;
	cout << "(2) Anleitung" << endl;
	cout << "(3) Beenden" << endl;
	cin >> Eingabe;

	if ( Eingabe == 1 )
	{
		cout << "Spiel" << endl;
		newSystem( "PAUSE" );
	}
	if ( Eingabe == 2 )
	{
		cout << "Anleitung" << endl;
		this->anleitung( );
	}
	if ( Eingabe == 3 )
		return 0;

	// TODO: "Spiel" und "Anleitung" implementieren.
	return 0;
}

int Console::anleitung()
{
	cout << endl << "== Verfuegbare Spielsteine ==" << endl << endl;

	cout << "[* ] - Der L-Baustein" << endl;
	cout << "[* ]" << endl;
	cout << "[**]" << endl;

	cout << endl;

	cout << "[ *] - Der J-Baustein" << endl;
	cout << "[ *]" << endl;
	cout << "[**]" << endl;

	cout << endl;
	newSystem( "PAUSE" );
	cout << endl;

	cout << "[*] - Der S-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[ *]" << endl;

	cout << endl;

	cout << "[ *] - Der Z-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[* ]" << endl;

	cout << endl;
	newSystem("PAUSE");
	cout << endl;

	cout << "[ *] - Der T-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[ *]" << endl;

	cout << endl;
	newSystem("PAUSE");
	cout << endl;

	cout << "[ *] - Der O-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[ *]" << endl;

	cout << endl;
	newSystem("PAUSE");
	cout << endl;

	cout << "[*]  - Der I-Baustein" << endl;
	cout << "[*]" << endl;
	cout << "[*]" << endl;
	cout << "[*]" << endl;

	cout << endl;

	newSystem("PAUSE");

	return 0;
}

void Console::set_console( short breite , short hoehe )
{
#ifdef __unix__

#endif

#ifdef _WIN32
	hCon = GetStdHandle( STD_OUTPUT_HANDLE );
	SMALL_RECT size;
	COORD b_size;

	size.Left = 0;
	size.Top = 0;
	size.Right = breite;
	size.Bottom = hoehe;
	b_size.X = breite + 1;
	b_size.Y = hoehe + 1;

	SetConsoleWindowInfo( hCon , true , & size );
	SetConsoleScreenBufferSize( hCon , b_size );
#endif
}
