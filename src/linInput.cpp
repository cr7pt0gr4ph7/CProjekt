/*
 * linInput.cpp
 *
 *  Created on: 27.06.2013
 *      Author: soeren.berken-mersma
 */

#include "linInput.h"

int translateVKeyCode(int vKeyLinux) {
	switch(vKeyLinux) {
	// A
	case (97):
			return 65;

	// D
	case (100):
			return 68;

	// S
	case (115):
			return 83;

	// W
	case (119):
			return 87;

	// TODO: Arrow-Keys sind nicht in ASCII definiert.
/*
	// Left-Arrow
	case (37):
			return 37;

	// Right-Arrow
	case ():
			return 39;

	// Down-Arrow
	case ():
			return 40;

	// Up-Arrow
	case ():
			return 38;
*/
	// ESC
	case (27):
			return 27;

	// P
	case (70):
			return 80;
	}
}

