#pragma once

#include "SDL.h"
#include "../math/Vector2D.h"

struct MovementComponent {
    float speed;
    Vector2D movement;
    SDL_RendererFlip flip;
};
