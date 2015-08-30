/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents a ship's  block on game board and it's behavior
****************************************/

#include "Block.h"

Block::Block(): Coordinates(0, 0) {}
Block::Block(int x, int y): Coordinates(x, y) {}
Block::~Block() {}

/*************************************************************************
* Function name: isAt
* The Input: coordinates to search for
* The output: whether or not the block is on the spec. coordinates
* The Function operation: tells if the block is on the spec. coordinates
*************************************************************************/
bool Block::isAt(const Coordinates coords) {
	return (x == coords.getX() &&
			y == coords.getY());
}

/*************************************************************************
* Function name: moveBy
* The Input: x and y coordinates to move by
* The output: none
* The Function operation: moves the block x cells down and y cells right
*************************************************************************/
void Block::moveBy(const int x, const int y) {
	setX(getX() + x);
	setY(getY() + y);
}
