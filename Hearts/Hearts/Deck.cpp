#include "Deck.h"

Deck::Deck()
{
	deck.reserve(number_of_cards);
	int card = 0;
	while(card < number_of_cards)
	{
		for(int i = clubs; i <= spades; i = i+1)
		{
			for(int j = deuce; j<= ace; j++)
			{
				
				Card newCard(static_cast<Value>(j), static_cast<Suit>(i));
				deck.at(card) = newCard;
				card++;
			}
		}
	}
}	