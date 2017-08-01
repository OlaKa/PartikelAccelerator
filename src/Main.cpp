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
#include "Swarm.h"
#include <math.h>
using namespace std;
using namespace monitor;

int main() {

	srand(time(NULL));

	Screen screen;

	if (screen.init() == false) {
		cout << "Error initialising SDL." << endl;
	}

	Swarm swarm;

	while (true) {

		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);

		unsigned char green =
				(unsigned char) ((1 + sin(elapsed * 0.0001)) * 125);
		unsigned char red = (unsigned char) ((1 + sin(elapsed * 0.0002)) * 125);
		unsigned char blue = (unsigned char) ((1 + sin(elapsed * 0.0003)) * 125);

		const Particle * const pParticles = swarm.getParticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2
					+ Screen::SCREEN_HEIGHT / 2;
			screen.setPixel(x, y, red, green, blue);
		}

		/*


		 for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
		 for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
		 screen.setPixel(x, y, red, green, blue);
		 }
		 }
		 */

		screen.boxBlur();
		screen.update();

		if (screen.ProcessEvent() == false) {
			break;
		}
	}

	screen.close();

	return 0;
}
