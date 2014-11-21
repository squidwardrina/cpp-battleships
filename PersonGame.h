/*
 * PersonGame.h
 *
 *  Created on: Nov 18, 2014
 *      Author: rina
 */

#ifndef PERSONGAME_H_
#define PERSONGAME_H_

#include "Game.h"

/*
 *
 */
class PersonGame: public Game {
public:
	PersonGame();
	virtual ~PersonGame();
	void playOneTurn();
};

#endif /* PERSONGAME_H_ */
