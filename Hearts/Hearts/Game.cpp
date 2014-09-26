#include "Game.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;



bool Game::searchFor2ofClubs(Computer computer)
{
	for(size_t i = 0; i < computer.hand.size(); i++)
	{
		if((computer.hand[i].suitName(computer.hand[i].getSuit()) == "Clubs") && (computer.hand[i].valueName(computer.hand[i].getValue()) == "Deuce"))
			return true;
		else
			return false;
	}
	return false;
	
}

bool Game::searchFor2ofClubs(Player player)
{
	for(size_t i = 0; i < player.hand.size(); i++)
	{
		if(player.hand[i].suitName(player.hand[i].getSuit()) == "Clubs" && player.hand[i].valueName(player.hand[i].getValue()) == "Deuce")
			return true;
		else
			return false;
	}
	return false;
}

Game::Game()
{
	
	isGameOver = false;
	
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
	deck.shuffle(15);
	computer1.addCardToHand(deck.deal());
	computer2.addCardToHand(deck.deal());
	computer3.addCardToHand(deck.deal());
	player1.addCardToHand(deck.deal());
	if(searchFor2ofClubs(computer1))
	{
		computer1.playsFirst = true;
		cout << "Player 2 goes first." << endl;
	}
	if(searchFor2ofClubs(computer2))
	{
		computer2.playsFirst = true;
		cout << "Player 3 goes first." << endl;
	}
	if(searchFor2ofClubs(computer3))
	{
		computer3.playsFirst = true;
		cout << "Player 4 goes first." << endl;
	}
	if(searchFor2ofClubs(player1))
	{
		player1.playsFirst = true;
		cout << "Player 1 goes first." << endl;
	}
	

	int number_of_rounds = 13; // Since each player has 13 cards and they play once per round their will be 13 rounds
	for(int i = 0; i < number_of_rounds; i++)
	{
		

	}

	deck.refreshDeck();

}


