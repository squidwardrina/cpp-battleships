/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description: represents the ship class
****************************************/

#ifndef SHIP_H_
#define SHIP_H_

#include <list>
#include "Consts.h"
#include "Block.h"

using namespace std;
class Ship {
private:
	list<Block> blocks;

public:
	Ship();
	Ship(int, const Coordinates&);
	virtual ~Ship();
	bool isKilled(); // checks if the ship was hit
	void drawOn(char[BOARD_SIZE][BOARD_SIZE]); // draws the ship on the board
	void draw(int); // draws the ship by type (used before creation)
	bool isAt(const Coordinates&); // tells if the ship is on those coords
	bool handleFire(const Coordinates&); // handles fire on the ship and tells the result
	const list<Block>& getBlocks() const {
		return blocks;
	}
};

#endif /* SHIP_H_ */
