/*
 * Game.h
 *
 *  Created on: Nov 18, 2014
 *      Author: rina
 */

#ifndef GAME_H_
#define GAME_H_

#include "Player.h"

/*
 *
 */
class Game {
protected:
	Player * player1;
	Player * player2;
	bool isPlayer1Turn;

public:
	Game();
	virtual ~Game();
	virtual void playOneTurn();
};

#endif /* GAME_H_ */
