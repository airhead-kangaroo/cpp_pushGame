#pragma once
#include <iostream>
#include "Map.h"
#include "Player.h"
#include "Luggage.h"

class Stage {
public:
	Stage();
	~Stage();
	void show();
	bool move(char key);
	enum MapObject {
		OBJ_NONE, OBJ_WALL, OBJ_PLAYER, OBJ_LUGGAGE,OBJ_GOAL
	};
private:
	const int MAP_WIDTH = 10;
	const int MAP_HEIGHT = 10;
	const static int MAX_LUGGAGES = 2;
	Map *map;
	Player *player;
	Luggage * luggages[MAX_LUGGAGES];
	void showMap();
	void keyCheck(int *x, int *y, char key);
	void playerMove(int x, int y);
	bool luggageMove(int x, int y);
	bool isClear();
};

