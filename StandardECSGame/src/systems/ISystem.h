#pragma once

#include "../../dependencies/entt.hpp"

class ISystem {
public:
	virtual void update(entt::registry& registry, float deltaTime) = 0;
};
