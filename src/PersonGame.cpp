/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the game class
* 					Responsible for running the battleships game logic,
* 					in mode "computer vs. player"
****************************************/

#include "PersonGame.h"

#include <iostream>
#include <string>

#include "ComputerPlayer.h"
#include "Consts.h"
#include "GameMenu.h"
#include "PersonPlayer.h"

PersonGame::PersonGame() : Game() {
	GameMenu menu;
	player1 = new PersonPlayer(menu.getNameFor("human [you]"));
	player2 = new ComputerPlayer(menu.getNameFor("your computer enemy"));
}

PersonGame::~PersonGame(){
	delete player1;
	delete player2;
}

/*************************************************************************
* Function name: drawBoards
* The Input: -
* The output: -
* The Function draws the player's board and enemy's board as user sees it
*************************************************************************/
void PersonGame::drawBoards() {
	cout << "\n\tYour board right now:\n";
	player1->drawBoard();
	cout << "\n\t" << player2->getName() << "'s board sketch:\n";
	((PersonPlayer*) player1)->drawEnemySketch();
	cout << "\n";
}
