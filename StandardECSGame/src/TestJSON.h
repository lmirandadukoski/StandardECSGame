#pragma once

#include <iostream>
#include <fstream>

#include "../dependencies/json.hpp"
using json = nlohmann::json;
#include "SDL.h"
#include "SDL_image.h"

#include "math/Vector2DInt.h"
#include "helpers/TextureHelper.h"

#define TILESET_FILE "assets/rawTestTileset.png"
#define TILESET_JSON_FILE "levels/TestTileset.json"
#define TILEMAP_JSON_FILE "levels/test2.json"

struct Tile {
	SDL_Rect src, dst;
};

class TestJSON {
public:
	inline void readJSONFile() {
		std::ifstream tileset(TILESET_JSON_FILE);
		auto tilesetData = json::parse(tileset);

		_tileDimension = { _getJSONData(tilesetData, "tilewidth"), _getJSONData(tilesetData, "tileheight") };
		_setDimension = { _getJSONData(tilesetData, "imageheight") / _tileDimension.y, _getJSONData(tilesetData, "imagewidth") / _tileDimension.x };

		//std::cout << "N Rows: " << _setNumRows << " N Cols: " << _setNumColumns << std::endl;
	}

	inline void loadTileMap() {
		std::ifstream tileMap(TILEMAP_JSON_FILE);
		_tileMapData = json::parse(tileMap);

		_tilesetTexture = helpers::createTexture(TILESET_FILE);
		_tiles = _readLayerData();
	}

	inline void renderTileMap() {
		std::vector<Tile>::iterator it;
		int i = 0;
		
		for (it = _tiles.begin(); it != _tiles.end(); it++, i++) {
			Tile tile = *it;
			SDL_RenderCopy(window.getRenderer(), _tilesetTexture, &tile.src, &tile.dst);
			//std::cout << "Drawing tile from source texture pos x = " << tile.src.x << ", y = " << tile.src.y << ", and placing it in x = " << tile.dst.x << ", y = " << tile.dst.y << std::endl;
		}
	}

private:
	json _tileMapData;
	Vector2DInt _tileDimension;
	Vector2DInt _setDimension;

	SDL_Texture* _tilesetTexture;
	std::vector<Tile> _tiles;

	inline std::vector<Tile> _readLayerData() {
		std::vector<Tile> tiles;

		json::iterator it;
		int i = 0;

		json layers = _getJSONData(_tileMapData, "layers");
		for (it = layers.begin(); it != layers.end(); it++, i++) {			
			std::cout << "Processing layer " << i << "..." << std::endl;
			json layer = *it;

			std::vector<Tile> layerTiles = _processLayer(layer);
			tiles.insert(tiles.begin(), layerTiles.begin(), layerTiles.end());
		}

		return tiles;
	}

	inline std::vector<Tile> _processLayer(json layer) {
		std::vector<Tile> layerTiles;

		json layerData = _getJSONData(layer, "data");
		Vector2DInt layerDimension = { _getJSONData(layer, "width"), _getJSONData(layer, "height") };
		
		json::iterator it;
		int i = 0;

		for (it = layerData.begin(); it != layerData.end(); ++it, i++) {
			if (*it == 0) {
				continue;
			}

			int tileID = *it - 1;
			Vector2DInt coordinate = { tileID / _setDimension.y, tileID % _setDimension.y };

			Vector2DInt src = { 0, 0 };
			Vector2DInt dst = { 0, 0 };
			_calculateTileSourceAndDestinationCoordinates(layerDimension, coordinate, _tileDimension, i, src, dst);

			Tile tile = _createTile(src, dst, _tileDimension);
			layerTiles.push_back(tile);
		}

		return layerTiles;
	}

	inline void _calculateTileSourceAndDestinationCoordinates(Vector2DInt layerDimension, Vector2DInt coordinate, Vector2DInt tileDimension, int itIndex, Vector2DInt& src, Vector2DInt& dst) {
		src = { coordinate.y * tileDimension.y, coordinate.x * tileDimension.x };
		dst = { (itIndex % layerDimension.x) * tileDimension.x, (itIndex / layerDimension.x) * tileDimension.y };
	}

	inline json _getJSONData(json data, std::string key) {
		return data[key];
	}

	inline Tile _createTile(Vector2DInt src, Vector2DInt dst, Vector2DInt tileDimension) {
		Tile tile{};
		tile.src = { src.x, src.y, tileDimension.x, tileDimension.y };
		tile.dst = { dst.x, dst.y, tileDimension.x, tileDimension.y };

		std::cout << "Creating tile from source texture pos x = " << src.x << ", y = " << src.y << ", and placing it in x = " << dst.x << ", y = " << dst.y << std::endl;

		return tile;
	}
};