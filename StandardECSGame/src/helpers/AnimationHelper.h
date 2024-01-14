#pragma once

#include "SDL.h"
#include "SDL_image.h"

#include "../components/AnimationComponent.h"
#include "TextureHelper.h"

namespace helpers {
	AnimationComponent createAnimation(const char* fileName, int index, int frames, int speed);
}