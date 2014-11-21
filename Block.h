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
	Block();
	Block(int, int);
	virtual ~Block();
	void moveBy(int, int);
	bool isAt(Coordinates coords);
};

#endif /* BLOCK_H_ */
