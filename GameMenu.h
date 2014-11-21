/*
 * GameFlow.h
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#ifndef GAMEMENU_H_
#define GAMEMENU_H_

#include "Game.h"

class GameMenu {
public:
	GameMenu();
	virtual ~GameMenu();
	Game * getGameMode();
};

#endif /* GAMEMENU_H_ */
