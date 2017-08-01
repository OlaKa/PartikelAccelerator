/*
 * Screen.h
 *
 *  Created on: 30 jul 2017
 *      Author: ola
 */

#ifndef SCREEN_H_
#define SCREEN_H_
#include <iostream>
#include <SDL.h>
using namespace std;

namespace monitor {

class Screen {

private:
	SDL_Window *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture *m_texture;
	Uint32 *m_buffer1;
	Uint32 *m_buffer2;

public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

public:
	Screen();
	bool init();
	void close();
	bool ProcessEvent();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green,Uint8 blue);
	void boxBlur();

	virtual ~Screen();
};

} /* namespace monitor */

#endif /* SCREEN_H_ */
