#include "Computer.h"

Computer::Computer()
{
	vector<Card> hand;
	score = 0;
	playsFirst = false;
}

Card Computer::playCard(vector<Card> trick)
{
	Card play;
	if(playsFirst)
	{
		for(int i = 0; i< hand.size(); i++)
		{
			Suit s = hand[i].getSuit();
			Value v = hand[i].getValue();

			if ((s == 0) && (v == 0))
			{
				play = hand[i];
				hand.erase(hand.begin() + i);
				return play;
			}
		}
	}

	for (size_t i = 0; i < hand.size(); i++)			//You must follow what was led if you can.
	{
		if(trick.size() > 0)
		{
			if (trick[0].getSuit() == hand[i].getSuit())
			{
				play = hand[i];
				hand.erase(hand.begin() + i);
				return play;
			}
		}
	}

	for (size_t j = 0; j < hand.size(); j++)			//If you have none of what was led, you then want to get rid of your hearts.
	{
		Suit s = hand[j].getSuit();
		Value v = hand[j].getValue();

		if (((s == hearts) || ((s == spades) && (v == queen))) && (trick.size() > 0))
		{
			play = hand[j];
			hand.erase(hand.begin() + j);
			return play;
		}
	}

	play = hand[0];			//If you have no hearts, simply play a card.
	hand.erase(hand.begin());
	return play;
}

void Computer::addCardToHand(vector<Card> cards)
{
	hand = cards;

	return;
}