/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description: represents the player class
****************************************/

#include "Player.h"

#include "Board.h"
#include "Consts.h"
#include "Coordinates.h"

#include <iostream>

Player::Player(string name) {
	board = new Board();
	this->name = name;
}

Player::~Player() {
	delete board;
}

/*************************************************************************
* Function name: drawBoard
* The Input: -
* The output: -
* The Function operation: draws the player's board
*************************************************************************/
void Player::drawBoard() {
	board->draw();
}

/*************************************************************************
* Function name: placeShips
* The Input: -
* The output: -
* The Function operation: handles placing all the ships on player's board
*************************************************************************/
void Player::placeShips() {
	const int SHIP_NUM = 6;

	// Go over the ships and choose place for them
	for (int i = 1; i <= SHIP_NUM; ++i) {
		placeShip(i);
	}
}

/*************************************************************************
* Function name:
* The Input: -
* The output: -
* The Function operation:
*************************************************************************/
bool Player::canPlaceShip(Ship& ship) {
	list<Block> blocks = ship.getBlocks();
	list<Block>::iterator block;

	// Go over the blocks and check if they are all placed OK
	for (block = blocks.begin(); block != blocks.end(); ++block) {
		// Check if block is out of the board
		if (block->getX() >= BOARD_SIZE ||
				block->getY() >= BOARD_SIZE ||
				block->getX() < 0 || block->getY() < 0){
			return false;
		}

		// Check for ship overlapping
		if (board->isShipAt(*block)) {
			return false;
		}
	}
	return true; // no problem to place the ship
}

/*************************************************************************
* Function name:handleAttack
* The Input: attack coordinates
* The output: the attack result
* The Function operation: handled attack at the spec. coords and returns
* 			the result after the attack (hit miss or kill)
*************************************************************************/
HitStatus Player::handleAttack(const Coordinates& coords) {
	return board->fireAt(coords);
}

/*************************************************************************
* Function name:isDestroyed
* The Input: -
* The output: true if all the user's ships are destroyed
* The Function operation: checks whether the user's ships are all destroyed
*************************************************************************/
bool Player::isDestroyed() {
	return board->isEmpty();
}
