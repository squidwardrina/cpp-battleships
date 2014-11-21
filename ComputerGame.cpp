
#include "ComputerGame.h"
#include "ComputerPlayer.h"

ComputerGame::ComputerGame() : Game(){
	player1 = new ComputerPlayer();
	player2 = new ComputerPlayer();
}

ComputerGame::~ComputerGame() {
	delete player1;
	delete player2;
}

void ComputerGame::playOneTurn() {
}
