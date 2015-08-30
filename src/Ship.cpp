/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description: represents the ship class
****************************************/
#include "Ship.h"
#include "Consts.h"
#include <iostream>

Ship::Ship() {}
Ship::~Ship() {}
Ship::Ship(int size, const Coordinates& coords) {
	int x = coords.getX();
	int y = coords.getY();
	if (!(size % 2)) {
		for (int i = 0; i < size / 2; ++i) {
			// Create 2 cols of blocks
			blocks.push_back(Block(x + i, y));
			blocks.push_back(Block(x + i, y + 1));
		}
	} else {
		for (int i = 0; i < size; ++i) {
			// Create a row of blocks
			blocks.push_back(Block(x, y + i));
		}
	}
}

/*************************************************************************
* Function name: isKilled
* The Input: -
* The output: true if the ship is destroyed
* The Function operation: checks if the ship has no more blocks
*************************************************************************/
bool Ship::isKilled() {
	return blocks.size() == 0;
}

/*************************************************************************
* Function name: drawOn
* The Input: the array to draw on
* The output: -
* The Function operation: draws the ship on the board array
*************************************************************************/
void Ship::drawOn(char boardArr[BOARD_SIZE][BOARD_SIZE]) {
	const char BLOCK = '#';
	// Go over the blocks and draw them on the board
	list<Block>::iterator block;
	for (block = blocks.begin(); block != blocks.end(); ++block) {
		int x = block->getX();
		int y = block->getY();
		boardArr[x][y] = BLOCK; // draw a block on the board
	}
}

/*************************************************************************
* Function name: draw
* The Input: the ship's type
* The output: -
* The Function operation: draws the ship by type (used before the blocks are created)
*************************************************************************/
void Ship::draw(int type) {
	if (!(type % 2)) {
		// Draw 2 cols of blocks
		for (int i = 0; i < type / 2; ++i) {
			cout << "**\n";
		}
	} else {
		// Draw a row of blocks
		for (int i = 0; i < type; ++i) {
			cout << "*";
		}
	}
}

/*************************************************************************
* Function name: isAt
* The Input: coordinates being searched
* The output: true if the ship is on those coords
* The Function operation: checks if the ship is at specified coordinates
*************************************************************************/
bool Ship::isAt(const Coordinates& coordinates) {
	// Search over the ship's blocks
	list<Block>::iterator block;
	for (block = blocks.begin(); block != blocks.end(); ++block) {
		if (block->isAt(coordinates)) {
			return true; // block found at the coordinates
		}
	}

	// No block found on the specified coordinates
	return false;
}

/*************************************************************************
* Function name: handleFire
* The Input: coordinates being fired
* The output: true if the ship was hit
* The Function operation: handles fire on the ship and tells if it was hit
*************************************************************************/
bool Ship::handleFire(const Coordinates& coordinates) {
	// Search over the ship's blocks
	list<Block>::iterator block;
	for (block = blocks.begin(); block != blocks.end(); ++block) {
		if (block->isAt(coordinates)) {
			blocks.erase(block);
			return true;
		}
	}

	// No block found on the specified coordinates
	return false;
}
