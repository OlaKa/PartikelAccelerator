//============================================================================
// Name        : Project.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include "Screen.h"

using namespace std;
using namespace monitor;

int main() {

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initializing SDL" << endl;
	}

	while (true) {
		if (screen.ProcessEvent() == false) {
			break;
		}

	}

	screen.close();
	return 0;
}
