#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

class Window {
public:
	Window();
	~Window();

	bool tryCreateWindow();
	void clearRenderer();
	void updateRenderer();
	void destroyWindow();

	SDL_Window* getWindow() { return _window; }
	SDL_Renderer* getRenderer() { return _renderer; }

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};

extern Window window;