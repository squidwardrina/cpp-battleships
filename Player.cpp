/*
 * Player.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "Player.h"

Player::Player() {
	board = new Board();
}

Player::~Player() {
	delete board;
}
