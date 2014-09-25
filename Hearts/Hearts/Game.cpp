#include "Game.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

Game::Game()
{
	Deck deck;
	Player player1;
	Computer computer1, computer2, computer3;
	bool isGameOver = false;
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