#pragma once

#include "ISystem.h"
#include "../Input.h"
#include "../components/InputComponent.h"

class InputSystem final : public ISystem {
public:
	InputSystem() = default;
	~InputSystem() = default;

	void update(entt::registry &registry, float deltaTime);
};

