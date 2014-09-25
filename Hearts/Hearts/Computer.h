#include "Card.h"
#include <vector>

using std::vector;

class Computer
{
public:
	Computer();
	Card playCard(vector<Card> trick);
<<<<<<< HEAD
	void addCardToHand(vector<Card> cards);
=======
	int getScore(){return score;}
	void addScore(int points){score += points;}
>>>>>>> d49dca4f8a930b9c8bd5e540d7233d6342f41a3b
private:
	vector<Card> hand;
	int score;
};
