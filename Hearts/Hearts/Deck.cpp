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
	//Seeds the random number generator
	srand(time(NULL));

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

		
		//Swaps a random amount of cards around to random positions. If this isn't present
		//The two of clubs will always be on top no matter how many times you shuffle
		for(int i = rand()%20; i<30; i++)
		{
			int random = rand() % 52;
			int random1= rand() % 52;
			if(random != random1)
			{
				Card temp;
				temp = deck[random];
				deck[random] = deck[random1];
				deck[random1] = temp;
			}
		}
		Card temp;
		int random = (rand() % 50) + 1;
		temp = deck[1];
		deck[1] = deck[random];
		deck[random] = temp;

	}

}

//Assumes that its dealing 13 cards for a 4 person game
vector<Card> Deck::deal()
{
	vector<Card> hand;
	for(int i = 0;i<(number_of_cards/4); i++)
	{
		hand.push_back(deck[0]);
		deck.erase(deck.begin());
	}

	return hand;
}

void Deck::refreshDeck()
{
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