#include "Card.h"
#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

class Player
{
public:
	vector<Card> hand;
	int getScore(){return score;}
	void addScore(int points){score += points;}
	Card play_a_card( vector<Card> trick, bool areHeartsBroken);
	bool playsFirst;
	Player();
	void addCardToHand(vector<Card> cards);

private:
	int card_to_play;
	void display_hand();
	void display_played_cards(vector<Card> trick);
	bool card_is_good(int card_to_play, vector<Card> trick, bool heartsAreBroken);
	int score;
};