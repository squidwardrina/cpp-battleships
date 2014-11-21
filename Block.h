/*
 * Block.h
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "Coordinates.h"

class Block: public Coordinates {
public:
	Block(int, int);
	virtual ~Block();
	bool isAt(Coordinates coords);
	//void draw(Board);
};

#endif /* BLOCK_H_ */
