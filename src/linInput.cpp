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
	}

	//TODO: Keycodes ergänzen
	/*
	// Left-Arrow
	case ():
			return 37;

	// Right-Arrow
	case ():
			return 39;

	// Down-Arrow
	case ():
			return 40;

	// ESC
	case ():
			return 27;

	// P
	case ():
			return 80; */
}

