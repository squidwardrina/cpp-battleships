/*
 * Ship.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "Ship.h"

Ship::Ship()
{
}

Ship::~Ship()
{
	//delete [] this->blocks;
}

void Ship::setSize(int size)
{
	int x = 0;
	int y = 0;

	if (size % 2)
	{
		for (int i = 0; i < size / 2; ++i)
		{
			// create 2 rows of blocks
		}
	}
	else
	{
		for (int i = 0; i < size; ++i)
		{
			// create a block row
		}
	}
}

bool Ship::isKilled() {
	return true;
}

Ship::Ship(int int1) {
}
