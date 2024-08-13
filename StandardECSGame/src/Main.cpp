#include <iostream>
#include <algorithm>

#include "Input.h"
#include "Time.h"

#include "game/DemoGame.h"

int main(int argx, char* argv[]) {
    DemoGame game;
    
    bool initialised = game.createNewGame();
    if (!initialised) {
        return 0;
    }

    game.load();

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
                game.update(TIME_STEP);
            }

            accumulator -= TIME_STEP;
        }

        game.render(TIME_STEP);
    }

    game.destroy();    

	return 0;
}
