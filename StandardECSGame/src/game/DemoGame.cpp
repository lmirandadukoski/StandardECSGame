#include "DemoGame.h"

DemoGame::DemoGame() : _gameScene{ _createGameSceneConfig() } {
    _testJSON.readJSONFile();
}

bool DemoGame::createNewGame() {
    return window.tryCreateWindow();
}

void DemoGame::load() {
    _testJSON.loadTileMap();
    _gameScene.load();
    window.setWindowTitle(_getWindowTitle().c_str());
}

void DemoGame::update(float deltaTime) {
    _gameScene.update(deltaTime);
}

void DemoGame::render(float deltaTime) {
    window.clearRenderer();
    _testJSON.renderTileMap();
    _gameScene.render(deltaTime);
    window.updateRenderer();    
}

void DemoGame::destroy() {
    _gameScene.destroy();
    window.destroyWindow();
}

GameSceneConfig DemoGame::_createGameSceneConfig() {
    GameSceneConfig config = { "Game",
        "./assets/Penguin_SpriteSheet.png",
        "./assets/rawTestTileset.png",
        "levels/TestTileset.json",
        "levels/test2.json",
        { 0.0f, 50.0f },
        1.5f };

    return config;
}

std::string DemoGame::_getWindowTitle() {
    std::string currentTitle = "Demo Game - ";
    currentTitle.append(_gameScene.getName());

    return currentTitle;
}
