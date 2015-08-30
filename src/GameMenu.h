/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the menu class
* 					responsible for dialog with the user
****************************************/

#ifndef GAMEMENU_H_
#define GAMEMENU_H_

#include <string>

#include "Consts.h"

class Game;

class GameMenu {
public:
	GameMenu();
	virtual ~GameMenu();

	Game * getGameMode(); // recieves the chosen game mood
	ComputerLevel getLevelFor(std::string); // gets level for computer
	std::string getNameFor(std::string); // gets name for player
};

#endif /* GAMEMENU_H_ */
