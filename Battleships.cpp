/* 8921003 322193285 Rina Fridland */

#include "GameMenu.h"
#include "Game.h"

int main()
{
	GameMenu menu;
	Game * game = menu.getGameMode();

	// TODO: easy/hard/kaka

	while (true)
	{
		game->playOneTurn();
	}

	delete game;
	return 1;
}
