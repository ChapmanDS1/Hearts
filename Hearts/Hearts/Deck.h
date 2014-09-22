#include "Card.h"
#include <vector>
using std::vector;

class Deck{
public:
	Deck();
	void shuffle(int number);
	Card deal();

private:
	int const number_of_cards = 52;
	vector<Card> deck;
};