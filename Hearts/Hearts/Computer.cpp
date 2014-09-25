#include "Computer.h"

Computer::Computer()
{
	vector<Card> hand;
}

Card Computer::playCard(vector<Card> trick)
{
	Card play;

	for (int i = 0; i < hand.size(); i++)			//You must follow what was led if you can.
	{
		if (trick[0].getSuit() == hand[i].getSuit())
		{
			play = hand[i];
			hand.erase[i];
			return play;
		}
	}

	for (int j = 0; j < hand.size(); j++)			//If you have none of what was led, you then want to get rid of your hearts.
	{
		Suit s = hand[j].getSuit;
		Value v = hand[j].getValue;

		if (((s == hearts) || ((s == spades) && (v == queen))) && (trick.size() > 0))
		{
			play = hand[j];
			hand.erase[j];
			return play;
		}
	}

	play = hand[0];			//If you have no hearts, simply play a card.
	hand.erase[0];
	return play;
}