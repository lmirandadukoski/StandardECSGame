#pragma once

#include "SDL.h"

#include "./math/Vector2D.h"

struct InputAxes {
	Vector2D input = { 0.0f, 0.0f };
	int faceDirection = 0;
};

class Input {
public:
	int pollInputEvent();
	bool hasQuit() { return _hasQuit; }
	InputAxes getInputAxes() { return _inputAxes; }

private:
	SDL_Event _polledEvent;
	bool _hasQuit;
	InputAxes _inputAxes;

	void _calculateInputAxes(SDL_Event evt);
};

extern Input input;