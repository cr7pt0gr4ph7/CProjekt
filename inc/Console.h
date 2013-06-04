/*
 * @file	Console.h
 *
 * @date	21.05.2013
 * @author	Superuser
 * @brief	Console.h
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "Interface.h"

class Console : public Interface
{
	private:
		HANDLE hCon;

		HANDLE getHCon() const
		{
			return hCon;
		}

	public:
		Console();
		virtual ~Console();

		int oberflaeche();
		int anleitung();
		void set_console( short breite , short hoehe );
};

#endif /* CONSOLE_H_ */
