#pragma once

#include "SDL.h"

#define FPS 60.0f
#define TIME_STEP 1.0f / FPS
#define MAX_FRAME_TIME 0.25f

static class Time {
public:
	static float elapsedTimeInSeconds();
};