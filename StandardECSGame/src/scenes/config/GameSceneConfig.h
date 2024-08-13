#pragma once

#include "../../math/Vector2D.h"

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
};
