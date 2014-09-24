#include "Computer.h"
#include "Deck.h"
#include "Player.h"

class Game
{
public:
	Game(); //Setups the deck, and player objects, and initializes isGameOver to false
	void playGame();//Calls the playHand function in a loop until a player gets over 100 points.
	
					 

private:
	Player player1;
	Computer computer1, computer2, computer3;
	Deck deck;
	bool areHeartsBroken;
	bool isGameOver; //Defaults to true. The playGame function sets this to true once a player gets over 100 points.
	void playHand(); // Called indefinitely by playGame() until the game is over. setsup the deck and deals out hands
					 // sets areHeartsBroken to false. Keeps playing until all players are out of cards 
					 // and then adds points to each player according to how many points they've won. Checks also to see if any player shot the moon
};

