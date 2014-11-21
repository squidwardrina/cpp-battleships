/*
 * Board.h
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>
#include "Ship.h"
#include "Consts.h"

class Board {
private:
	vector<Ship*> ships;
	int shipsCount;

public:
	Board();
	virtual ~Board();
	void draw();
};

#endif /* BOARD_H_ */
