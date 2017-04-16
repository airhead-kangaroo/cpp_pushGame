#include "Stage.h"

Stage::Stage() {
	map = new Map(MAP_HEIGHT,MAP_WIDTH);
	player = new Player(2, 2);
	luggages[0] = new Luggage(4, 2);
	luggages[1] = new Luggage(3, 6);
	
}

Stage::~Stage() {
	delete map;
	delete player;
	delete luggages;
}

void Stage::show() {
	map->resetMapData();
	map->setMapData(player->getX(),player->getY(),OBJ_PLAYER);
	for (int i = 0; i < MAX_LUGGAGES; i++) {
		map->setMapData(luggages[i]->getX(), luggages[i]->getY(), OBJ_LUGGAGE);
	}
	showMap();
}

void Stage::showMap() {
	map->resetIndex();
	int count = 0;
	while (map->hasNext()) {
		if (count % (MAP_WIDTH + 1) == 0) { // && count != 0‰Á‚¦‚é
			std::cout << std::endl;
		}
		else {
			int data = map->getNextData();
			char mark;
			switch (data) {
			case OBJ_NONE:
				mark = ' ';
				break;
			case OBJ_WALL:
				mark = '#';
				break;
			case OBJ_PLAYER:
				mark = '@';
				break;
			case OBJ_LUGGAGE:
				mark = '*';
				break;
			case OBJ_GOAL:
				mark = 'O';
				break;
			default:
				mark = 'E';
			}
			std::cout << mark;
		}
		count++;
	}
	std::cout << std::endl;
	std::cout << "a:left s:up x:right z:down" << std::endl;
	std::cout << "press key :";
}

bool Stage::move(char key) {
	system("cls");
	int a, b;
	a = b = 0;
	int *x = &a;
	int	*y = &b;
	this->keyCheck(x, y, key);
	this->playerMove(*x, *y);
	if (this->isClear()) {
		return false;
	}
	return true;
}

void Stage::keyCheck(int *x, int *y, char key) {

	switch (key) {
	case 'a':
		*x = -1;
		break;
	case 's':
		*y= -1;
		break;
	case 'z':
		*y = 1;
		break;
	case 'x':
		*x = 1;
		break;
	}
}

void Stage::playerMove(int x, int y) {
	int data = map->getMapData(player->getX() + x, player->getY() + y);
	switch (data) {
	case OBJ_NONE:
		player->setPosition(x, y);
		break;
	case OBJ_LUGGAGE:
		if (luggageMove(x, y)) {
			player->setPosition(x, y);
		}
		break;
	case OBJ_WALL:
		break;
	case OBJ_GOAL:
		player->setPosition(x, y);
		break;
	}
}

bool Stage::luggageMove(int x, int y) {
	for (int i = 0; i < MAX_LUGGAGES; i++) {
		if (luggages[i]->getX() == player->getX() + x && luggages[i]->getY() == player->getY() + y) {
			int ldata = map->getMapData(luggages[i]->getX() + x, luggages[i]->getY() + y);
			switch (ldata) {
			case OBJ_NONE:
				luggages[i]->setPosition(x, y);
				luggages[i]->setOnGoalFlag(false);
				return true;
			case OBJ_GOAL:
				luggages[i]->setPosition(x, y);
				luggages[i]->setOnGoalFlag(true);
				return true;
			default:
				return false;
			}
		}
	}
	

}

bool Stage::isClear() {
	for (int i = 0; i < MAX_LUGGAGES; i++) {
		if (!luggages[i]->getIsOnGoal()) {
			return false;
		}
	}
	return true;
}
