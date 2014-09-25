#include "Deck.h"
#include "Computer.h"
#include <vector>
using std::vector;

class Player
{
public:
	vector<Card> hand;
private:
	Card play_a_card( vector<Card> trick);
	int card_to_play;
	void display_hand();
	void display_played_cards(vector<Card> trick);
	bool card_is_good(int card_to_play, vector<Card> trick);
};