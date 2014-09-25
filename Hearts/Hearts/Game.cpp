#include "Game.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

Game::Game()
{
	deck.shuffle(10);
	bool isGameOver = false;
	bool areHeartsBroken = false;
}

void Game::playGame()
{
	Game hearts; 

	while (!hearts.isGameOver)
	{
		hearts.playHand();
	}

	return;
}