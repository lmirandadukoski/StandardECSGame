#include "GameScene.h"

GameScene::GameScene(const char* tileMapFilePath) {
	_name = "Game Scene";
    _tileMapFilePath = tileMapFilePath;
}

GameScene::~GameScene() {

}

void GameScene::initialiseScene() {
	_createPlayerEntity();
}

void GameScene::update(float deltaTime) {
    InputAxes inputAxes = input.getInputAxes();
    _updateInput(inputAxes);
    _updateMovement(deltaTime);
}

void GameScene::render(float deltaTime) {
    _updateAnimations(deltaTime);
}

void GameScene::destroyScene() {
	_registry.clear();
}

void GameScene::_createPlayerEntity() {
    auto entity = _registry.create();

    _registry.emplace<TransformComponent>(entity, Vector2D{ 0.0f, 50.0f });

    std::map<const char*, AnimationComponent> animations = {
        {"idle", helpers::createAnimation(PLAYER_SPRITESHEET_PATH, 0, 2, 100)},
        {"walk", helpers::createAnimation(PLAYER_SPRITESHEET_PATH, 1, 4, 100)},
    };
    _registry.emplace<AnimatorComponent>(entity, animations);

    _registry.emplace<MovementComponent>(entity, 1.5f, Vector2D{ 0.0f, 0.0f }, SDL_FLIP_NONE);

    _registry.emplace<InputComponent>(entity, Vector2D{ 0.0f, 0.0f }, 0);
}

void GameScene::_createTileMap() {

}

void GameScene::_updateInput(InputAxes inputAxes) {  
    auto inputView = _registry.view<InputComponent>();
    for (auto [entity, inp] : inputView.each()) {
        inp.movement.x = inputAxes.input.x;
        inp.movement.y = inputAxes.input.y;
        inp.faceDir = inputAxes.faceDirection;
    }
}

void GameScene::_updateMovement(float deltaTime) {
    auto movementView = _registry.view<TransformComponent, const InputComponent, MovementComponent>();
    for (auto [entity, pos, inp, mvn] : movementView.each()) {        
        mvn.movement.x = inp.movement.x;
        mvn.movement.y = 0.0f;
        mvn.flip = inp.faceDir > 0 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;
        pos.position.x += mvn.movement.x * mvn.speed;
        pos.position.y += mvn.movement.y * mvn.speed;
    }
}

void GameScene::_updateAnimations(float deltaTime) {
    auto view = _registry.view<const TransformComponent, const MovementComponent, AnimatorComponent>();
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

const char* GameScene::_getTargetAnimationName(float vMagnitude) {
    if (vMagnitude > 0.0f) {
        return "walk";
    }
    return "idle";
}