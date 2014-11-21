/****************************************
* Student Name:		Rina Fridland
* Exercise Name:
* File description:
****************************************/

#include "Block.h"

Block::Block(): Coordinates(0, 0) {}
Block::Block(int x, int y): Coordinates(x, y) {}
Block::~Block() {}

bool Block::isAt(Coordinates coords) {
	return (x == coords.getX() &&
			y == coords.getY());
}

void Block::moveBy(int x, int y) {
	setX(getX() + x);
	setY(getY() + y);
}
