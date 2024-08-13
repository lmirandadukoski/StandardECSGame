#include <iostream>
#include <algorithm>

#include "Window.h"
#include "Input.h"
#include "Time.h"

#include "scenes/GameScene.h"
#include "scenes/config/GameSceneConfig.h"
#include "math/Vector2D.h"

#include "TestJSON.h"
#include "Main.h"

TestJSON test;

GameSceneConfig constructGameSceneConfig() {
    GameSceneConfig config = { "Game", 
        "./assets/Penguin_SpriteSheet.png", 
        "./assets/rawTestTileset.png", 
        "levels/TestTileset.json", 
        "levels/test2.json",
        { 0.0f, 50.0f } };
    /*config.name = "Game";
    config.playerSpriteSheetPath = "./assets/Penguin_SpriteSheet.png";
    config.tilesetTexturePath = "./assets/rawTestTileset.png";
    config.tilesetJSONPath = "levels/TestTileset.json";
    config.tileMapJSONPath = "levels/test2.json";*/

    return config;
}

int main(int argx, char* argv[]) {
    GameSceneConfig config = constructGameSceneConfig();
    GameScene gameScene = {config};
    test.readJSONFile();

    bool initialised = window.tryCreateWindow(config.name);
    if (!initialised) {
        return 0;
    }

    test.loadTileMap();
    gameScene.load();

    bool hasQuit = false;       
    float lastTime = Time::elapsedTimeInSeconds();
    float accumulator = 0.0f;

    while (!hasQuit) {    
        float currentTime = Time::elapsedTimeInSeconds();
        float frameTime = currentTime - lastTime;
        
        lastTime = currentTime;
        accumulator += frameTime;

        while (accumulator >= TIME_STEP) {
            while (input.pollInputEvent()) {
                hasQuit = input.hasQuit();
                gameScene.update(TIME_STEP);
            }

            accumulator -= TIME_STEP;
        }

        window.clearRenderer();
        test.renderTileMap();
        gameScene.render(TIME_STEP);
        window.updateRenderer();
    }

    gameScene.destroy();
    window.destroyWindow();

	return 0;
}
