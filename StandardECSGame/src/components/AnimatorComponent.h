#pragma once

#include <map>
#include "AnimationComponent.h"

struct AnimatorComponent {
    std::map<const char*, AnimationComponent> animations;
};
