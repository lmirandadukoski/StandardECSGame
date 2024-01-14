#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_image.h"

#include "../Window.h"

namespace helpers {
	SDL_Texture* createTexture(const char* fileName);
}
