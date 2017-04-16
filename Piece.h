#pragma once

class Piece {
public:
	Piece(int x, int y);
	~Piece();
	int getX();
	int getY();
	void setPosition(int deltaX, int deltaY);
private:
	int x;
	int y;
};
