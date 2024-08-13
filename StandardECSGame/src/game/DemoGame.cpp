#include "DemoGame.h"

DemoGame::DemoGame() : _gameScene{ _createGameSceneConfig() } {
    _testJSON.readJSONFile();
}

bool DemoGame::createNewGame() {
    return window.tryCreateWindow(_gameScene.getName());
}

void DemoGame::load() {
    _testJSON.loadTileMap();
    _gameScene.load();
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
        { 0.0f, 50.0f } };
    /*config.name = "Game";
    config.playerSpriteSheetPath = "./assets/Penguin_SpriteSheet.png";
    config.tilesetTexturePath = "./assets/rawTestTileset.png";
    config.tilesetJSONPath = "levels/TestTileset.json";
    config.tileMapJSONPath = "levels/test2.json";*/

    return config;
}
