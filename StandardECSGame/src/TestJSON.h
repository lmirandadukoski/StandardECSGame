#pragma once

#include <iostream>
#include <fstream>

#include "../dependencies/json.hpp"
using json = nlohmann::json;
#include "SDL.h"
#include "SDL_image.h"

#include "helpers/TextureHelper.h"

#define TILESET_FILE "assets/rawTestTileset.png"
#define TILESET_JSON_FILE "levels/TestTileset.json"
#define TILEMAP_JSON_FILE "levels/TestTileMap.json"

struct Tile {
	SDL_Rect src, dst;
};

class TestJSON {
public:
	inline void readJSONFile() {
		std::ifstream tileset(TILESET_JSON_FILE);
		auto tilesetData = json::parse(tileset);

		_tileHeight = tilesetData["tileheight"];
		_tileWidth = tilesetData["tilewidth"];
		_numRows = tilesetData["imageheight"] / _tileHeight;
		_numColumns = tilesetData["imagewidth"] / _tileWidth;

		std::cout << "N Rows: " << _numRows << " N Cols: " << _numColumns << std::endl;
	}

	inline void loadTileMap() {
		std::ifstream tileMap(TILEMAP_JSON_FILE);
		_tileMapData = json::parse(tileMap);

		_tilesetTexture = helpers::createTexture(TILESET_FILE);

		auto layerData = _tileMapData["layers"][0]["data"];
		int height = _tileMapData["layers"][0]["height"];
		int width = _tileMapData["layers"][0]["width"];

		int idx = 0;
		for (json::iterator it = layerData.begin(); it != layerData.end(); ++it) {
			if (*it == 0) {
				continue;
			}

			int colIndex = *it % _numColumns;
			int rowIndex = (*it - colIndex) / _numColumns;

			//std::cout << idx << ": rowI = " << rowIndex << " colI = " << colIndex << " value = " << *it << '\n';

			Tile tile;
			tile.src = { rowIndex * _tileWidth, colIndex * _tileHeight, _tileWidth, _tileHeight };
			//std::cout << "src.x = " << tile.src.x << " src.y = " << tile.src.y << " src.w = " << tile.src.w << " src.h = " << tile.src.h << '\n';
			tile.dst = { 0, 0, 0, 0 };
			_tiles.emplace_back(tile);
			idx++;
		}
	}

	inline void renderTileMap() {
		int idx = 0;
		for (auto tile : _tiles) {
			SDL_RenderCopy(window.getRenderer(), _tilesetTexture, &tile.src, &tile.src);
			idx++;
		}

		std::cout << idx << std::endl;
	}

private:
	json _tileMapData;
	int _tileHeight, _tileWidth;
	int _numRows, _numColumns;

	SDL_Texture* _tilesetTexture;
	std::vector<Tile> _tiles;
};