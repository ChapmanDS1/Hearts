Hearts
======

COMP 220 Game

Computers Player class
	AI
	Hand 
	Add card to hand function. Takes a Card presumably from deck class and adds it to Hand.
	Play a card function
	Boolean - Plays first flag - default set to false
	

Player class
	Amount 
	hand 
	Add card to hand function. Takes a Card presumably from deck class and adds it to Hand.
	Play a card function
	Boolean - Plays first flag - default set to false

Deck class
	Default constructor populates the deck with one of each card
	Shuffle function
	Deal function returns a card and deletes that card from deck
	Vector of 52 filled with cards
	
Game class
	 3 computer objects and 1 player object - Computer objects named after 3 programmers
	Are_Hearts_Broken flag
	Is_Game_Over flag

	Setup Game Function
		Calls the shuffle function on the Deck
		Then deal one card at a time to each player until all 52 cards are dealt
		Checks to see which player has the 2 of clubs and set their flag to true
	Hand function - prompts player and computers to play a card
		Have the winner play the first card 
		Ensure that the player follows suit if he can
		Determine how many points each player has and add them up (Check to see if they shot the moon)
		check to see if anyone has over 100 points. If they do output to the screen the scores. And set Is_Game_Over to true
	

Main
	Create game object
	Calls setup game function
	While(!Is_Game_Over)
	{
		Hand function
	}

