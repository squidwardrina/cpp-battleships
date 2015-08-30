/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents any player's board in the game.
* 					responsible for the ships
****************************************/

#include "Board.h"

#include <iostream>
#include <iterator>

#include "Consts.h"

Board::Board() {}
Board::~Board() {}

/*************************************************************************
* Function name: initEmptyBoard
* The Input: board array
* The output: none
* The Function operation: initializes the board with empty cells
*************************************************************************/
void Board::initEmptyBoard(char boardArr[BOARD_SIZE][BOARD_SIZE]) {
	const char SEA = '~';
	// Initialize the empty board array
	for (int i = 0; i < BOARD_SIZE; ++i) {
		for (int j = 0; j < BOARD_SIZE; ++j) {
			boardArr[i][j] = SEA;
		}
	}
}

/*************************************************************************
* Function name: printBoard
* The Input: board array
* The output: none
* The Function operation: prints the board in console
*************************************************************************/
void Board::printBoard(char boardArr[BOARD_SIZE][BOARD_SIZE]) {
	// Print the columns numbers
	cout << "  ";
	for (int i = 0; i < BOARD_SIZE; ++i) {
		cout << i << " "; // just the columns' numbers
	}

	// Print rows numbers and each row
	for (int i = 0; i < BOARD_SIZE; ++i) {
		cout << "\n" << i << " "; // row's number
		for (int j = 0; j < BOARD_SIZE; ++j) {
			cout << boardArr[i][j] << " ";
		}
	}
}

/*************************************************************************
* Function name: draw
* The Input: -
* The output: -
* The Function operation: draws the board as a 2D array in console
*************************************************************************/
void Board::draw() {
	char boardArr[BOARD_SIZE][BOARD_SIZE]; // this would be the board "drawing"

	// Initialize the board array
	initEmptyBoard(boardArr);

	// Go over the ships and draw them on the board array
	vector<Ship>::iterator it;
	for (it = ships.begin(); it != ships.end(); ++it) {
		it->drawOn(boardArr);
	}

	// Print the board.
	printBoard(boardArr);
}

/*************************************************************************
* Function name: isShipAt
* The Input: coordinates
* The output: true/false
* The Function operation: tells if there is a ship on those coordinates
*************************************************************************/
bool Board::isShipAt(const Coordinates& coordinates) {
	// Go over the ships
	vector<Ship>::iterator ship;
	for (ship = ships.begin(); ship != ships.end(); ++ship) {
		if (ship->isAt(coordinates)) {
			return true; // found ship at the spec. coordinates
		}
	}
	return false; // no ship on these coordinates
}

/*************************************************************************
* Function name: addShip
* The Input: ship's type and first block's coordinates
* The output: -
* The Function operation: adds the specified ship
*************************************************************************/
void Board::addShip(const int shipType, const Coordinates* coords) {
	ships.push_back(Ship(shipType, *coords));
	delete coords;
}

/*************************************************************************
* Function name: isEmpty
* The Input: -
* The output: true if there is no ships left
* The Function operation: tells if there is no ships left
*************************************************************************/
bool Board::isEmpty() {
	return ships.empty();
}

/*************************************************************************
* Function name: fireAt
* The Input: the attack coordinates
* The output: the status of the attack - hit, miss or kill
* The Function operation: handles attack on the board's coordinates
*************************************************************************/
HitStatus Board::fireAt(const Coordinates& attackCoords) {
	vector<Ship>::iterator ship;
	for (ship = ships.begin(); ship != ships.end(); ++ship) {
		if (ship->handleFire(attackCoords)) {
			if (ship->isKilled()) {
				ships.erase(ship);
				return KILL;
			}
			return HIT;
		}
	}
	return MISS;
}
