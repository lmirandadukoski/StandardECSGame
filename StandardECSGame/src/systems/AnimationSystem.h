#pragma once

#include "ISystem.h"

#include "../helpers/AnimationHelper.h"
#include "../helpers/Vector2DHelper.h"
#include "../components/AnimationComponent.h"
#include "../components/AnimatorComponent.h"
#include "../components/MovementComponent.h"
#include "../components/TransformComponent.h"

class AnimationSystem final : public ISystem {
public:
	AnimationSystem() = default;
	~AnimationSystem() = default;

	void update(entt::registry &registry, float deltaTime);

private:
	const char* _getTargetAnimationName(float vMagnitude);
};

