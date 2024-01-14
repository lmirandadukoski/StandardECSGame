#include <iostream>
#include <algorithm>

#include "Window.h"
#include "Input.h"
#include "Time.h"

#include "scenes/GameScene.h"

#include "TestJSON.h"

GameScene gameScene{""};
TestJSON test;

int main(int argx, char* argv[]) {
    test.readJSONFile();

    bool initialised = window.tryCreateWindow();
    if (!initialised) {
        return 0;
    }

    test.loadTileMap();
    gameScene.initialiseScene();

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

    gameScene.destroyScene();
    window.destroyWindow();

	return 0;
}