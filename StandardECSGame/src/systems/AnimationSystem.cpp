#include "AnimationSystem.h"

void AnimationSystem::update(entt::registry &registry, float deltaTime) {
    auto view = registry.view<const TransformComponent, const MovementComponent, AnimatorComponent>();
    for (auto [entity, pos, mvn, anm] : view.each()) {
        float velMagnitude = helpers::getVectorMagnitude(mvn.movement);
        const char* targetAnimationName = _getTargetAnimationName(velMagnitude);
        auto targetAnimation = anm.animations.at(targetAnimationName);

        targetAnimation.sprite.src.x = targetAnimation.sprite.src.w * static_cast<int>((SDL_GetTicks() / targetAnimation.speed) % targetAnimation.frames);

        targetAnimation.sprite.dst.x = static_cast<int>(pos.position.x);
        targetAnimation.sprite.dst.y = static_cast<int>(pos.position.y);
        SDL_RenderCopyEx(window.getRenderer(), targetAnimation.sprite.texture, &targetAnimation.sprite.src, &targetAnimation.sprite.dst, NULL, NULL, mvn.flip);
    }
}

const char* AnimationSystem::_getTargetAnimationName(float vMagnitude) {
    if (vMagnitude > 0.0f) {
        return "walk";
    }
    return "idle";
}
