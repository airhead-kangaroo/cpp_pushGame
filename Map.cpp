#include "Map.h"

Map::Map(int width, int height) {
	this->mapWidth = width;
	this->mapHeight = height;
	this->loadMap();
	this->duplicateMap();
	this->pointer = 0;
}

Map::~Map() {

}

void Map::loadMap() {
	std::ifstream ifs(fileName);
	if (ifs.fail()) {
		std::cout << "file error" << std::endl;
		exit(100);
	}
	originalMap = new int*[mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		originalMap[i] = new int[mapWidth];
		char buf[256];
		ifs.getline(buf, 256);
		for (int j = 0; j < mapWidth; j++) {
			originalMap[i][j] = buf[j] - '0';
		}
	}
}

int Map::getMapData(int x, int y) {
	return mapData[y][x];
}

void Map::setMapData(int x, int y, int data) {
	mapData[y][x] = data;
}

bool Map::hasNext() {
	if (pointer >= mapWidth * mapHeight) {
		return false;
	}
	else {
		return true;
	}
}

int Map::getNextData() {
	int data;
	if (pointer == 0) {
		data = mapData[0][0];
	}
	else {
		data = mapData[pointer / mapWidth][pointer % mapWidth];
	}
	pointer++;
	return data;
}

void Map::resetIndex() {
	pointer = 0;
}

void Map::duplicateMap() {
	mapData = new int*[mapHeight];
	for (int i = 0; i < mapHeight; i++) {
		mapData[i] = new int[mapWidth];
		for (int j = 0; j < mapWidth; j++) {
			mapData[i][j] = originalMap[i][j];
		}
	}
}

void Map::resetMapData() {
	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {
			mapData[i][j] = originalMap[i][j];
		}
	}
}