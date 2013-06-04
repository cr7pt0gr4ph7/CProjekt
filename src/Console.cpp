/*
 * @file	Console.cpp
 *
 * @date	21.05.2013
 * @author	Superuser
 * @brief	Console.cpp
 */

#include <Windows.h>
#include <iostream>
#include "Console.h"

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
		system( "PAUSE" );
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
	cout << endl << "== Verfügbare Spielsteine ==" << endl << endl;

	cout << "[* ] - Der L-Baustein" << endl;
	cout << "[* ]" << endl;
	cout << "[**]" << endl;

	cout << endl;

	cout << "[ *] - Der J-Baustein" << endl;
	cout << "[ *]" << endl;
	cout << "[**]" << endl;

	cout << endl;
	system( "PAUSE" );
	cout << endl;

	cout << "[*] - Der S-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[ *]" << endl;

	cout << endl;

	cout << "[ *] - Der Z-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[* ]" << endl;

	cout << endl;
	system( "PAUSE" );
	cout << endl;

	cout << "[ *] - Der T-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[ *]" << endl;

	cout << endl;
	system( "PAUSE" );
	cout << endl;

	cout << "[ *] - Der O-Baustein" << endl;
	cout << "[**]" << endl;
	cout << "[ *]" << endl;

	cout << endl;
	system( "PAUSE" );
	cout << endl;

	cout << "[*]  - Der I-Baustein" << endl;
	cout << "[*]" << endl;
	cout << "[*]" << endl;
	cout << "[*]" << endl;

	cout << endl;

	system( "PAUSE" );

	return 0;
}

void Console::set_console( short breite , short hoehe )
{
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
}
