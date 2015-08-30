/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents a ship's  block on game board and it's behavior
****************************************/

#ifndef BLOCK_H_
#define BLOCK_H_

#include "Coordinates.h"

class Block: public Coordinates {
public:
	Block();
	Block(int, int);
	virtual ~Block();

	void moveBy(const int, const int); // move the block
	bool isAt(const Coordinates); // checks if the block is at coords
};

#endif /* BLOCK_H_ */
