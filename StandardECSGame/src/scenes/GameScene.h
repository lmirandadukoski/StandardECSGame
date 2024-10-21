#pragma once

#include <iostream>

#include "IScene.h"
#include "config/GameSceneConfig.h"

#include "../components/AnimatorComponent.h"
#include "../components/MovementComponent.h"
#include "../components/TransformComponent.h"

#include "../systems/InputSystem.h"
#include "../systems/PlayerMovementSystem.h"
#include "../systems/AnimationSystem.h"

class GameScene : public IScene {
public:
	GameScene(GameSceneConfig config);
	~GameScene() = default;

	std::string getName();

	void load();
	void update(float deltaTime);
	void render(float deltaTime);
	void destroy();

private:
	void _createPlayerEntity();
	void _createTileMap();

	GameSceneConfig _config;
	std::vector<ISystem*> _updateSystems, _renderSystems;
};
