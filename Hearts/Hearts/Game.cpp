#include "Game.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

Game::Game()
{
	
	bool isGameOver = false;
	
}

void Game::playGame()
{
	while (!isGameOver)
	{
		playHand();
	}

	return;
}

void Game::playHand()
{
	areHeartsBroken = false;
	if(searchFor2ofClubs(computer1))
		computer1.playsFirst = true;
	if(searchFor2ofClubs(computer2))
		computer2.playsFirst = true;
	if(searchFor2ofClubs(computer3))
		computer3.playsFirst = true;
	if(searchFor2ofClubs(player1))
		player1.playsFirst = true;
	computer1.addCardToHand(deck.deal());
	computer2.addCardToHand(deck.deal());
	computer3.addCardToHand(deck.deal());
	player1.addCardToHand(deck.deal());

	int number_of_rounds = 13; // Since each player has 13 cards and they play once per round their will be 13 rounds
	for(int i = 0; i < number_of_rounds; i++)
	{
		

	}
}

bool searchFor2ofClubs(Computer computer)
{
	for(size_t i; i < computer.hand.size(); i++)
	{
		if(computer.hand[i].suitName(computer.hand[i].getSuit()) == "clubs" && computer.hand[i].valueName(computer.hand[i].getValue()) == "deuce")
			return true;
		else
			return false;
	}
	
}
bool searchFor2ofClubs(Player player)
{
	for(size_t i; i < player.hand.size(); i++)
	{
		if(player.hand[i].suitName(player.hand[i].getSuit()) == "clubs" && player.hand[i].valueName(player.hand[i].getValue()) == "deuce")
			return true;
		else
			return false;
	}
	
}