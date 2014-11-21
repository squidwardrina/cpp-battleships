/*
 * ComputerPlayer.h
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Player.h"

class ComputerPlayer: public Player {
public:
	ComputerPlayer();
	virtual ~ComputerPlayer();
	Coordinates * makeGuess();
	bool handleAttack(Coordinates hitCoordinates);
};

#endif /* COMPUTERPLAYER_H_ */
