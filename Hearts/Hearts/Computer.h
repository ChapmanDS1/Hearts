#include "Card.h"
#include <vector>

using std::vector;

class Computer
{
public:
	Computer();
	Card playCard(vector<Card> trick);
	int getScore(){return score;}
	void addScore(int points){score += points;}
private:
	vector<Card> hand;
	int score;
};
