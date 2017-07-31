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
		cout << "Error initialising SDL." << endl;
	}

	while (true) {

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);

		screen.update();

		if (screen.ProcessEvent() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
