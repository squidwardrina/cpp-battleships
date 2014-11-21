/*
 * ComputerPlayer.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "ComputerPlayer.h"
#include <stdlib.h>

ComputerPlayer::ComputerPlayer() {}

ComputerPlayer::~ComputerPlayer() {}

Coordinates * ComputerPlayer::makeGuess() {
	int x = rand() % 10;
	int y = rand() % 10;
	return new Coordinates(x, y);
}

bool ComputerPlayer::handleAttack(Coordinates hitCoordinates) {
}
