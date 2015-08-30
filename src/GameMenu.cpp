/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the menu class
* 					responsible for dialog with the user
****************************************/

#include "GameMenu.h"

#include <cstdlib>
#include <iostream>

#include "ComputerGame.h"
#include "Consts.h"
#include "PersonGame.h"

using namespace std;

GameMenu::GameMenu() {}
GameMenu::~GameMenu() {}

/*************************************************************************
* Function name: getGameMode
* The Input: -
* The output: game object of the selected mode
* The Function operation: gets selected game mode from user and creates the game
*************************************************************************/
Game * GameMenu::getGameMode() {
	// Get game mode from user
	cout << "WazzAAAppp?! =)))\n"
			"Please select game mode:\n"
			"\tp - for Player vs. Computer\n"
			"\tc - for Computer vs. Computer\n";
	string mode;
	cin >> mode;

	// Validate the input
	while (mode.compare("c") != 0 && mode.compare("p") != 0) {
		cout << "Wrong input. Try again\n";
		cin >> mode;
	}

	// Return the relevant game
	if (mode.compare("c") == 0) {
		return (new ComputerGame());
	}
	return new PersonGame();
}

/*************************************************************************
* Function name: getLevelFor
* The Input: computer's name
* The output: selected level
* The Function operation: gets level for the spec. computer from user
*************************************************************************/
ComputerLevel GameMenu::getLevelFor(std::string compName) {
	cout << "\nChoose level for " << compName << ":\n"
			"\t0 - Easy\n\t1 - Medium\n\t2 - hard\nSo? ";
	string strLevel;
	cin >> strLevel;

	// Validate the input
	while (strLevel.compare("0") != 0 && strLevel.compare("1") != 0 &&
			strLevel.compare("2") != 0) {
		cout << "Wrong input. Try again\n";
		cin >> strLevel;
	}

	// Return the chosen level
	return (ComputerLevel)(strLevel[0] - 48);
}

/*************************************************************************
* Function name: getNameFor
* The Input: player to get name for
* The output: the name of the spec. player
* The Function operation: gets a name for the spec. player from user
*************************************************************************/
std::string GameMenu::getNameFor(std::string player) {
	string name;
	cout << "Enter name for " << player << ":\t";
	cin >> name;
	while (name == "") {
		cout << "Nothing was entered. Try again: ";
		cin >> name;
	}
	return name;
}
