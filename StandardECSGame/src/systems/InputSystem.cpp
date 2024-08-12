#include "InputSystem.h"

void InputSystem::update(entt::registry &registry, float deltaTime) {
	InputAxes inputAxes = input.getInputAxes();

    auto inputView = registry.view<InputComponent>();
    for (auto [entity, inp] : inputView.each()) {
        inp.movement.x = inputAxes.input.x;
        inp.movement.y = inputAxes.input.y;
        inp.faceDir = inputAxes.faceDirection;
    }
}
