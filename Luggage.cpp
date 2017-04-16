#include "Luggage.h"

Luggage::Luggage(int x, int y) : Piece(x, y) {
	this->isOnGoal = false;
}

void Luggage::setOnGoalFlag(bool flag) {
	this->isOnGoal = flag;
}

bool Luggage::getIsOnGoal() {
	return isOnGoal;
}