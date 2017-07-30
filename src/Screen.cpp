/*
 * Screen.cpp
 *
 *  Created on: 30 jul 2017
 *      Author: ola
 */
#include "Screen.h"

namespace monitor {

Screen::Screen() :
		m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL) {

}

bool Screen::init() {

	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed!" << endl;
		return false;
	}

	m_window = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (m_window == NULL) {
		SDL_Quit();
		return 2;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (m_renderer == NULL) {
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	if (m_texture == NULL) {
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}

	Uint32 *m_buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(m_buffer, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	//buffer[30000] = 0xFFFFFFFF;

	for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
		m_buffer[i] = 0x808000FF;
	}

	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
	SDL_RenderPresent(m_renderer);

	return true;
}

void Screen::close() {
	delete[] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();

}
bool Screen::ProcessEvent() {
	SDL_Event event;
	while (SDL_PollEvent (&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

} /* namespace monitor */
