/*
 * @file	Console.h
 *
 * @date	21.05.2013
 * @author	Superuser
 * @brief	Console.h
 */

#ifndef STARTSCR_H_
#define STARTSCR_H_
#include "ui/screens/Interface.h"

#ifndef HANDLE
typedef void * HANDLE;
#endif

class Startscr : public Interface
{
	private:
		HANDLE hCon;

		HANDLE getHCon() const
		{
			return hCon;
		}

	public:
		Startscr();
		virtual ~Startscr();

		int startscrPrintout();
		int instructionsPrintout();
		void setWindow( short breite , short hoehe );
};

#endif /* STARTSCR_H_ */
