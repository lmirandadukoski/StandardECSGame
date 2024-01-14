#pragma once

#include "SpriteComponent.h"

struct AnimationComponent {
    SpriteComponent sprite;
    int index;
    int frames;
    int speed;
};
