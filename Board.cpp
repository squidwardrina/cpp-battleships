/*
 * Board.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "Board.h"
#include "Consts.h"

Board::Board()
{
	shipsCount = SHIP_NUM;
	for (int i = 0; i < SHIP_NUM; ++i) {
		ships.push_back(new Ship(i));
	};
}

Board::~Board()
{
	ships.clear();
}

void Board::draw() {
}
