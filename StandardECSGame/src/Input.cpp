#include "Input.h"

Input input;

int Input::pollInputEvent() {
	int evt = SDL_PollEvent(&_polledEvent);
	_hasQuit = _polledEvent.type == SDL_QUIT;
    _calculateInputAxes(_polledEvent);
	return evt;
}

void Input::_calculateInputAxes(SDL_Event evt) {
    if (evt.type == SDL_KEYDOWN) {
        switch (evt.key.keysym.sym) {
        case SDLK_w:
            _inputAxes.input.y = -1.0f;
            break;
        case SDLK_a:
            _inputAxes.input.x = -1.0f;
            _inputAxes.faceDirection = 1;
            break;
        case SDLK_s:
            _inputAxes.input.y = 1;
            break;
        case SDLK_d:
            _inputAxes.input.x = 1;
            _inputAxes.faceDirection = 0;
            break;
        default:
            break;
        }
    }
    else if (evt.type == SDL_KEYUP) {
        switch (evt.key.keysym.sym) {
        case SDLK_w: case SDLK_s:
            _inputAxes.input.y = 0;
            break;
        case SDLK_a: case SDLK_d:
            _inputAxes.input.x = 0;
            break;
        default:
            break;
        }
    }
}
