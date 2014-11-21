/*
 * Ship.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "Ship.h"
#include <vector>

Ship::Ship() {
}

Ship::Ship(int size) {
	setSize(size);
}

Ship::~Ship() {
	blocks.clear();
}

void Ship::setSize(int size) {
	// Create different ships according to their size
    if (size % 2) {
		for (int i = 0; i < size / 2; ++i) {
			// Create 2 rows of blocks
			blocks.push_back(new Block(i, 0));
			blocks.push_back(new Block(i, 1));
		}
	} else {
		for (int i = 0; i < size; ++i) {
			// Create a column of blocks
			blocks.push_back(new Block(0, i));
		}
	}
}

void Ship::moveTo(Coordinates startCoords) {
	list<Block*>::iterator it;
	int x = startCoords.getX();
	int y = startCoords.getY();

	// Iterate over ship's blocks and move them
	for (it = blocks.begin(); it != blocks.end(); it++) {
		(*it)->moveBy(x, y);
	}
}

bool Ship::isKilled() {
	return blocks.size() == 0;
}
