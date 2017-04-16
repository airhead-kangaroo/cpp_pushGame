#pragma once
#include <fstream>
#include <iostream>

class Map {
public:
	Map(int width, int heigth);
	~Map();
	int getMapData(int x, int y);
	void setMapData(int x, int y, int data);
	bool hasNext();
	int getNextData();
	void resetIndex();
	void resetMapData();
private:
	void loadMap();
	void duplicateMap();
	int mapWidth;
	int mapHeight;
	int **mapData;
	int **originalMap;
	int pointer;
	const char fileName[16] = "map.txt";
};
