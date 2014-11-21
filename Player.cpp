/*
 * Player.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "Player.h"

Player::Player() {
	this->board = new Board();
}

Player::~Player() {
	delete this->board;
}
