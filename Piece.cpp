#include "Piece.h"

Piece::Piece(int x, int y) {
	this->x = x;
	this->y = y;
}

Piece::~Piece() {

}

int Piece::getX() {
	return this->x;
}

int Piece::getY() {
	return this->y;
}

void Piece::setPosition(int deltaX, int deltaY) {
	this->x += deltaX;
	this->y += deltaY;
}