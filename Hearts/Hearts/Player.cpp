/* 
 Author: Chris Delposen
 Course: COMP 220, Computer Programming II 
 Date: 20 September 2014
 Description: This file defines the different parts of the player class.
*/ 



#include "Player.h"

Player::Player()
{
	score = 0;
	playsFirst = false;
}

void Player::display_hand()
{
	cout << "Your hand is: " << endl;
	for (size_t i = 1; i < hand.size() + 1; i++)
	{
		cout << i << ". " << hand[i].getValue() << " of " << hand[i].getSuit() << endl;
	}
	cout << endl;
}

void Player::display_played_cards(vector<Card> trick)
{
	cout << "The card(s) that have been played are: " << endl;
	for (size_t i = 0; i < trick.size(); i++)	// need to get the trick vector from the game class 
	{
		cout << trick[i].getValue() << " of " << trick[i].getSuit() << endl;
	}
}

bool Player::card_is_good(int card_to_play, vector<Card> trick, bool heartsAreBroken)
{
	string s;
	if (hand[card_to_play].getSuit() == trick[0].getSuit())
		return true;

	if ((trick.size() == 0) && (!heartsAreBroken) && hand[card_to_play].suitName(hand[card_to_play].getSuit()) == "heart" )
		return false; 

	for (size_t i = 0; i < hand.size(); i++)
	{
		if(hand[i].getSuit() == trick[0].getSuit())
			return false;
	}

	return true; 
}

Card Player::play_a_card(vector<Card> trick, bool areHeartsBroken)
{
	display_hand();
	display_played_cards(trick);

	
	do
	{
		cout << "Which card would you like to play?" << endl;
		cin >> card_to_play;
		card_to_play--;

		if(card_is_good(card_to_play, trick, areHeartsBroken))
		{
		return hand[card_to_play];
		}
		else
		{
			cout << "A different card must be played. Choose again. " << endl;
			display_hand();
		}
	}while(1);
}


void Player::addCardToHand(vector<Card> cards)
{
	hand = cards;

	return;
}