#include "Card.h"
#include <vector>

using std::vector;

class Computer
{
public:
	Computer();
	Card playCard(vector<Card> trick);
	void addCardToHand(vector<Card> cards);
private:
	vector<Card> hand;
};
