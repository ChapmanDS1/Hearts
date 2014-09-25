#include "Player.h"
#include "Deck.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

void Player::display_hand()
{
	cout << "Your hand is: " << endl;
	for (int i = 1; i < hand.size() + 1; i++)
	{
		cout << i << ". " << hand[i].getValue << " of " << hand[i].getSuit << endl;
	}
	cout << endl;
}

void Player::display_played_cards(vector<Card> trick)
{
	cout << "The card(s) that have been played are: " << endl;
	for (int i = 0; i < trick.size(); i++)	// need to get the trick vector from the game class 
	{
		cout << trick[i].getValue << " of " << trick[i].getSuit << endl;
	}
}

bool Player::card_is_good(int card_to_play, vector<Card> trick)
{
	if (hand[card_to_play].getSuit == trick[0].getSuit)
		return true;

	for (int i = 0; i < hand.size(); i++)
	{
		if(hand[i].getSuit == trick[0].getSuit)
			return false;
	}

	return true; 
}

Card Player::play_a_card(vector<Card> trick)
{
	display_hand();
	display_played_cards(trick);

	cout << "Which card would you like to play?" << endl;
	
	do
	{
		cin >> card_to_play;
		card_to_play--;

		if(card_is_good(card_to_play))
		{
		return hand[card_to_play];
		}
		else
		{
			cout << "A different card must be played. Choose again. " << endl;
			display_hand;
		}
	}while(1);
}


