/*
 * ComputerGame.h
 *
 *  Created on: Nov 18, 2014
 *      Author: rina
 */

#ifndef COMPUTERGAME_H_
#define COMPUTERGAME_H_

#include "Game.h"

/*
 *
 */
class ComputerGame: public Game {
public:
	ComputerGame();
	virtual ~ComputerGame();
	void playOneTurn();
};

#endif /* COMPUTERGAME_H_ */
