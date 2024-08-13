#pragma once

#include "../Window.h"
#include "../scenes/GameScene.h"
#include "../scenes/config/GameSceneConfig.h"

#include "../TestJSON.h"

class DemoGame {
public:
	DemoGame();
	~DemoGame() = default;

	bool createNewGame();
	void load();
	void update(float deltaTime);
	void render(float deltaTime);
	void destroy();

private:
	GameScene _gameScene;
	TestJSON _testJSON;

	GameSceneConfig _createGameSceneConfig();
};

