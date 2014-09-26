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
	cout << "Thank you for playing!" << endl;
	return;
}

int Game::whoWon(vector<Card> trick)
{
	Suit s;
	Value v;
	Card Max;
	int index = 0;
	s = trick[0].getSuit();
	v = trick[0].getValue();
	Max = trick[0];
	for(int i = 1; i < trick.size(); i++)
	{
		if((trick[i].getSuit() == s) && (trick[i].getValue() > v))
		{
			Max = trick[i];
			index = i;
		}
	}
	return index;

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
		vector<Card> trick;
		int player;
		int points;
		if(computer1.playsFirst = true)
		{
			trick.push_back(computer1.playCard(trick));
			trick.push_back(computer2.playCard(trick));
			trick.push_back(computer3.playCard(trick));
			player1.play_a_card(trick, areHeartsBroken);
			player = whoWon(trick);
			points = howManyPoints(trick);
			switch(player)
			{
				case 0:
					computer1.addScore(points);
					break;
				case 1:
					computer2.addScore(points);
					break;
				case 2:
					computer3.addScore(points);
					break;
				case 3:
					player1.addScore(points);
					break;
			}
			cout << "Computer 1 score: " << computer1.getScore() << endl;
			cout << "Computer 2 score: " << computer2.getScore() << endl;
			cout << "Computer 3 score: " << computer3.getScore() << endl;
			cout << "Player score: " << player1.getScore() << endl;

		}
		else if(computer2.playsFirst = true)
		{
			computer2.playCard(trick);
		}
		else if(computer3.playsFirst = true)
		{
			computer3.playCard(trick);
		}
		else if(player1.playsFirst = true)
		{
			player1.play_a_card(trick, areHeartsBroken);
		}

	}
	
	deck.refreshDeck();
	if(player1.getScore() >= 100)
	{
		cout << "You lost!" << endl;
		isGameOver = true;
	}
	if(computer1.getScore() >= 100)
	{
		cout << "You didn't lose!" << endl;
		isGameOver = true;
	}
	if(computer2.getScore() >= 100)
	{
		cout << "You didn't lose!" << endl;
		isGameOver = true;
	}
	if(computer3.getScore() >= 100)
	{
		cout << "You didn't lose!" << endl;
		isGameOver = true;
	}
}

int Game::howManyPoints(vector<Card> trick)
{
	int points = 0;
	for(int i = 0; i < trick.size(); i++)
	{
		if(trick[i].getSuit() == 2)
		{
			points++;
		}
		if((trick[i].getSuit() == 3) && (trick[i].getValue() == 11))
		{
			points = points + 13;
		}
	}
	return points;
}

