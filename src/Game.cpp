/****************************************
* Student Name:		Rina Fridland
* Exercise Name:	Assignment 1
* File description:	represents the game class
* 					responsible for the major game logic
* 					independently of the game mood
****************************************/

#include "Game.h"

#include <iostream>
#include <map>

#include "Coordinates.h"

//#include "Player.h"

Game::Game() {
	isPlayer1Turn = true;
	player1 = NULL;
	player2 = NULL;
}

Game::~Game() {}

/*************************************************************************
* Function name: playOneTurn
* The Input: -
* The output: -
* The Function operation: prepares the current turn - one player attacks
* 			and the other handles the attack.
*************************************************************************/
void Game::playOneTurn() {
	// Get the relevant player for this turn and his enemy
	Player * currPlayer;
	Player * enemy;
	if (isPlayer1Turn) {
		currPlayer = player1;
		enemy = player2;
	} else {
		currPlayer = player2;
		enemy = player1;
	}

	// The relevant player plays his turn
	Coordinates * guess = currPlayer->makeGuess();
	HitStatus hitStatus = enemy->handleAttack(*guess);
	currPlayer->sendHitFeedback(*guess, hitStatus);

	// Print information about the turn
	showTurn(currPlayer->getName(), *guess, hitStatus);

	// If player missed - turn goes to next player
	if (hitStatus == MISS) {
		isPlayer1Turn = !isPlayer1Turn;
	}

	// Done. Free the memory of prev. guess
	delete guess;
}

/*************************************************************************
* Function name: placeShips
* The Input: -
* The output: -
* The Function operation: places the ships on boards of both players
*************************************************************************/
void Game::placeShips() {
	player1->placeShips();
	player2->placeShips();
}

/*************************************************************************
* Function name: isOver
* The Input: -
* The output: true if the game is over (have a winner)
* The Function operation: tells if the game is over (have a winner)
*************************************************************************/
bool Game::isOver() {
	return player1->isDestroyed() || player2->isDestroyed();
}

/*************************************************************************
* Function name: getWinnerName
* The Input: -
* The output: the name of the winner. NULL if no winner yet
* The Function operation: gets the name of the winner. NULL if no winner yet
*************************************************************************/
string Game::getWinnerName() {
	if (player2->isDestroyed()) {
		return player1->getName(); // player 1 won
	} else if (player1->isDestroyed()) {
		return player2->getName(); // player 2 won
	} else {
		return NULL; //nobody won (shouldn't happen. just for logic)
	}
}

/*************************************************************************
* Function name: showTurn
* The Input: name of the player who played the turn, his guess and result
* The output: -
* The Function operation: displays the information about the played turn
*************************************************************************/
void Game::showTurn(string name, Coordinates& guess, HitStatus& status) {
	string hitStatuses[] = {"HIT", "MISS", "KILL"};

	cout << "\n" << name << " hits: "
			"(" << guess.getX() << ", " << guess.getY() << ")."
			"\tResult: " << hitStatuses[status] << "!\n";
	if (status != MISS) {
		cout << name << " gets another turn.\n";
	}
}
