#pragma once

#include "ISystem.h"

#include "../components/InputComponent.h"
#include "../components/MovementComponent.h"
#include "../components/TransformComponent.h"

class PlayerMovementSystem final : public ISystem {
public:
	PlayerMovementSystem() = default;
	~PlayerMovementSystem() = default;

	void update(entt::registry &registry, float deltaTime);
};

