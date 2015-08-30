/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents any player's board in the game.
* 					responsible for the ships
****************************************/

#ifndef BOARD_H_
#define BOARD_H_

#include <vector>

#include "Ship.h"

class Board {
private:
	vector<Ship> ships;

protected:
	void printBoard(char boardArr[BOARD_SIZE][BOARD_SIZE]); // prints the board
	void initEmptyBoard(char boardArr[BOARD_SIZE][BOARD_SIZE]); // init board

public:
	Board();
	virtual ~Board();

	virtual void draw(); // draw the board
	bool isShipAt(const Coordinates&); // checks if there's a ship on the coords
	void addShip(const int, const Coordinates*); // adds new ship
	bool isEmpty(); // checks if the board is empty
	HitStatus fireAt(const Coordinates&); // handles fire at coords
};

#endif /* BOARD_H_ */
