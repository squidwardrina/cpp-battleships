
#include "PersonGame.h"
#include "PersonPlayer.h"
#include "ComputerPlayer.h"

PersonGame::PersonGame() : Game(){
	player1 = new PersonPlayer();
	player2 = new ComputerPlayer();

}

PersonGame::~PersonGame(){
	delete player1;
	delete player2;
}

void PersonGame::playOneTurn() {
}
