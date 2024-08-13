#include "GameScene.h"

GameScene::GameScene(GameSceneConfig config) {
    _config = config;
	_name = config.name;
}

void GameScene::load() {
    _updateSystems.push_back(new InputSystem());
    _updateSystems.push_back(new PlayerMovementSystem());
    _renderSystems.push_back(new AnimationSystem());

    _createTileMap();
	_createPlayerEntity();
}

void GameScene::update(float deltaTime) {
    for (auto& updateSystem : _updateSystems) {
        updateSystem->update(_registry, deltaTime);
    }
}

void GameScene::render(float deltaTime) {
    for (auto& renderSystem : _renderSystems) {
        renderSystem->update(_registry, deltaTime);
    }
}

void GameScene::destroy() {
	_registry.clear();
}

void GameScene::_createPlayerEntity() {
    auto entity = _registry.create();

    _registry.emplace<TransformComponent>(entity, _config.playerStartPosition);

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