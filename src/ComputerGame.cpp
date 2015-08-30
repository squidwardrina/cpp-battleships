/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	responsible for the game logic "comp. vs. comp."
****************************************/

#include "ComputerGame.h"

#include <iostream>
#include <string>

#include "ComputerPlayer.h"
#include "GameMenu.h"


ComputerGame::ComputerGame() : Game() {
	GameMenu menu;
	player1 = new ComputerPlayer(menu.getNameFor("computer 1"));
	player2 = new ComputerPlayer(menu.getNameFor("computer 2"));
}

ComputerGame::~ComputerGame() {
	delete player1;
	delete player2;
}

/*************************************************************************
* Function name: drawBoards
* The Input: -
* The output: -
* The Function operation: draws boards of both computers
*************************************************************************/
void ComputerGame::drawBoards() {
	cout << "\t" << player1->getName() << ":\n";
	player1->drawBoard();
	cout << "\n\t" << player2->getName() << ":\n";
	player2->drawBoard();
}

void ComputerGame::playOneTurn() {
	Game::playOneTurn();
	cout << "\nSay something when you're ready to continue. ";
	std::string dummy;
	cin >> dummy;
	cout << "\n";
}
