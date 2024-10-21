#pragma once

#include "../../math/Vector2D.h"
#include "../../components/AnimationComponent.h"
#include "../../helpers/AnimationHelper.h"

struct GameSceneConfig {
public:
	GameSceneConfig() = default;
	~GameSceneConfig() = default;

	const char* name;
	const char* playerSpriteSheetPath;
	const char* tilesetTexturePath;
	const char* tilesetJSONPath;
	const char* tileMapJSONPath;

	Vector2D playerStartPosition;
	float playerMovementSpeed;

	std::map<const char*, AnimationComponent> getPlayerAnimations() {
		std::map<const char*, AnimationComponent> animations = {
			{"idle", helpers::createAnimation(playerSpriteSheetPath, 0, 2, 100)},
			{"walk", helpers::createAnimation(playerSpriteSheetPath, 1, 4, 100)},
		};
		return animations;
	}
};
