/* 8921003 322193285 Rina Fridland */

#include <iostream>
#include <string>

#include "Game.h"
#include "GameMenu.h"

/*********************************************************************
* Program name:              * Battleships Game
*
* The operation:             * Simulates a battleships game.
*                              Possible modes:
*                              		- Computer vs. computer
*                              		- Computer vs. person
*                              Each computer has 3 levels:
*                              		- Easy (random moves)
*                              		- Medium (upon hits destroys the ship)
*                              		- Hard (strategic moves)
*********************************************************************/
int main() {
	GameMenu menu;
	Game * game = menu.getGameMode();

	// Prepare the game
	game->placeShips();
	cout << "\nThe ships were placed by both players.\tCurrent status:\n";
	game->drawBoards();

	// Play until one player wins
	cout << "\nLet's play! =)\n";
	while (!game->isOver()) {
		cout << "\n-------------------------------------------------------\n\n";
		game->drawBoards();
		game->playOneTurn();
		cout << "\nThis turn is over.";
	}

	// Congrats to the winner
	cout << "\n\nGame over! "<< game->getWinnerName() << " won.\n";

	delete game;
	return 0;
}
