#pragma once

#include <iostream>

#include "IScene.h"

#include "../helpers/AnimationHelper.h"
#include "../helpers/Vector2DHelper.h"
#include "../components/AnimationComponent.h"
#include "../components/AnimatorComponent.h"
#include "../components/MovementComponent.h"
#include "../components/SpriteComponent.h"
#include "../components/TransformComponent.h"

#include "../systems/InputSystem.h"
#include "../systems/PlayerMovementSystem.h"
#include "../systems/AnimationSystem.h"

#define PLAYER_SPRITESHEET_PATH "./assets/Penguin_SpriteSheet.png"

class GameScene : public IScene {
public:
	GameScene(const char* name);
	~GameScene() = default;

	void load();
	void update(float deltaTime);
	void render(float deltaTime);
	void destroy();

private:
	void _createPlayerEntity();
	void _createTileMap();

	std::vector<ISystem*> _updateSystems, _renderSystems;
};
