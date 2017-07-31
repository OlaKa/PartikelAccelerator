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
#include <math.h>
using namespace std;
using namespace monitor;

int main() {

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	while (true) {

		//int val= rand() % 255 + 1;
		//cout <<val <<endl;
		int elapsed = SDL_GetTicks();
		unsigned char green = (unsigned char)((1+sin(elapsed*0.0001))*125);
		unsigned char red = (unsigned char)((1+sin(elapsed*0.0002))*125);
		unsigned char blue = (unsigned char)((1+sin(elapsed*0.0003))*125);

		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
		}

		screen.update();

		if (screen.ProcessEvent() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
