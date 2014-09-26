#include "Card.h"
#include <vector>
using std::vector;
#include <cstdlib>
using std::rand;
#include <ctime>
using std::time;

class Deck{
public:
	Deck();
	void shuffle(int number);  // number = The number of times to run the shuffle algorithm. The higher the number the more swaps occur.
	vector<Card> deal(); 
	void refreshDeck();
private:
	static int const number_of_cards = 52;
	vector<Card> deck;
};