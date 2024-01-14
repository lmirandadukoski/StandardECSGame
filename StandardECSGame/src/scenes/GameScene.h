#pragma once

#include <iostream>

#include "IScene.h"

#include "../helpers/AnimationHelper.h"
#include "../helpers/Vector2DHelper.h"
#include "../components/AnimationComponent.h"
#include "../components/AnimatorComponent.h"
#include "../components/InputComponent.h"
#include "../components/MovementComponent.h"
#include "../components/SpriteComponent.h"
#include "../components/TransformComponent.h"

#include "../Input.h"

#define PLAYER_SPRITESHEET_PATH "./assets/Penguin_SpriteSheet.png"

class GameScene : public IScene {
public:
	GameScene(const char* tileMapFilePath);
	~GameScene();

	void initialiseScene();
	void update(float deltaTime);
	void render(float deltaTime);
	void destroyScene();

private:
	void _createPlayerEntity();
	void _createTileMap();
	void _updateInput(InputAxes inputAxes);
	void _updateMovement(float deltaTime);
	void _updateAnimations(float deltaTime);
	const char* _getTargetAnimationName(float vMagnitude);

	const char* _tileMapFilePath;
};
