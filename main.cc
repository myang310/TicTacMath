// Ming Yang

#include <iostream>
#include "board.h"

/*
 * Function main
 * Input:
 *		none
 * Process:
 *		Until someone achieves the game-winning condition, tracks the
 *		current player, continues the gameplay and displays the board
 *		each turn.
 *	Output:
 *		none
 */		

int main()
{
	Board board;
	bool currentPlayer = 0;		// tracks the current player
	board.initialize();
	board.printRules();

	while (board.play(currentPlayer))   // while win-condition is unmet, play on
	{
		board.display();
		currentPlayer = !currentPlayer;   // updates the player tracker variable after each turn
	}
	board.display();
	std::cout << "\nCongratulations player " << currentPlayer + 1   // prints winner
				 << ", you've won!\n" << std::endl;
	
	return 0;
}
