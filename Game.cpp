/*
 * Game.cpp
 *
 *  Created on: Nov 18, 2014
 *      Author: rina
 */

#include "Game.h"
#include <stddef.h>

Game::Game() {
	isPlayer1Turn = true;
	player1 = NULL;
	player2 = NULL;
}

Game::~Game() {
}

void Game::playOneTurn() {
	Coordinates * guess;

	// The relevant player plays his turn
	if (isPlayer1Turn) {
		guess = player1->makeGuess();
		isPlayer1Turn = false;
	} else {
		guess = player2->makeGuess();
		isPlayer1Turn = true;
	}

	delete guess;
}
