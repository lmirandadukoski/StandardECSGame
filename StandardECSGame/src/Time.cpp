#include "Time.h"

float Time::elapsedTimeInSeconds() {
	float t = SDL_GetTicks();
	t *= 0.001f;

	return t;
}