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
				deck.push_back(newCard);
				card++;
			}
		}
	}
}	
	

void Deck::shuffle(int number)
{
	vector<Card> deck1 = deck;

	int x = 0;
	while(x <number)
	{
		int counter = 0;
		for(int i = 0; i < number_of_cards; i +=2)
		{
			
			deck[counter] = deck1[i];
			counter++;
			
		}
		for(int i = 1; i < number_of_cards; i+=2)
		{
			
			deck[counter] = deck1[i];
			counter++;
		}
		x++;
		deck1 = deck;
	}

}