/*
 * GameFlow.cpp
 *
 *  Created on: Nov 16, 2014
 *      Author: rina
 */

#include "GameMenu.h"

#include <iostream>
#include <string>
#include "ComputerGame.h"
#include "PersonGame.h"

using namespace std;

GameMenu::GameMenu() {
	// TODO Auto-generated constructor stub

}

GameMenu::~GameMenu() {
	// TODO Auto-generated destructor stub
}



Game * GameMenu::getGameMode() {
	// Get game mode from user
	cout << "WazzAAAppp?! =)))\n"
			"Please select game mode:\n"
			"\tp - for Player vs. Computer\n"
			"\tc - for Computer vs. Computer\n";
	string mode;
	cin >> mode;

	// Validate the input
	while (mode.compare("c") != 0 && mode.compare("p") != 0)
	{
		cout << "Wrong input. Try again\n";
		cin >> mode;
	}

	// Return the relevant game
	if (mode.compare("p") == 0)
	{
		return (new ComputerGame());
	}
	return new PersonGame();
}
