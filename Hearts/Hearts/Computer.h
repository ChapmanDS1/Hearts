#include "Card.h"
#include <vector>

using std::vector;

class Computer
{
public:
	Computer();
	Card playCard(vector<Card> trick);
private:
	vector<Card> hand;
};
