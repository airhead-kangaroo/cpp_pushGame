#pragma once
#include "Piece.h"

class Luggage : public Piece{
public:
	Luggage(int x, int y);
	~Luggage();
	void setOnGoalFlag(bool);
	bool getIsOnGoal();
private:
	bool isOnGoal;
};