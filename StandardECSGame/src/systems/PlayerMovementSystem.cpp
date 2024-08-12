#include "PlayerMovementSystem.h"

void PlayerMovementSystem::update(entt::registry& registry, float deltaTime) {
    auto movementView = registry.view<TransformComponent, const InputComponent, MovementComponent>();
    for (auto [entity, pos, inp, mvn] : movementView.each()) {
        mvn.movement.x = inp.movement.x;
        mvn.movement.y = 0.0f;
        mvn.flip = inp.faceDir > 0 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        pos.position.x += mvn.movement.x * mvn.speed;
        pos.position.y += mvn.movement.y * mvn.speed;
    }
}
