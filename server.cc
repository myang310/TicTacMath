// Ming Yang

#include <iostream>
#include "board.h"

/*
 * Function Board::initialize
 * Input:
 *		none
 *	Process:
 *		Initializes the starting values of the board_ array to 0, spacesTaken_ to
 *		false and numbersTaken_ to false.
 *	Output:
 *		Updated board_, spacesTaken_, and numbersTaken_ to default values.
 */

void Board::initialize()
{
	for (int row = 0; row < GRID_SIZE_; row++)
		for (int col = 0; col < GRID_SIZE_; col++) {
			board_[row][col] = 0;
			spacesTaken_[row][col] = false;
		}

	for (int number = 0; number <= 10; number++) {
		numbersTaken_[number] = false;
	}
}

/*
 * Function Board::printRules
 * Input:
 *		none
 *	Process:
 *		none
 *	Output:
 *		Prints the rules of the game to the console.
 */

void Board::printRules()
{
	std::cout << "\nTic-Tac-Math is a lot like Tic-Tac-Toe. The game is played on\n"
				 << "a 3x3 grid; players take turns marking one cell at a time. The\n"
				 << "difference is that instead of placing Xs and Os on the grid,\n"
				 << "players place the numbers 1 to 9. And instead of trying to make\n"
				 << "a row, column, or diagonal filled with 3 Xs or 3 Os, the players\n"
				 << "try to make a row, column, or diagonal whose cells sum to 15.\n"
				 << "One wrinkle: each number can only be placed ONCE." << std::endl;
}

/*
 * Function Board::validateState
 * Input:
 *		input - the value of the number to be placed on the board by the player
 *	Process:
 *		Checks to see if the number inputted by the user has already been
 *		played on a previous turn.
 *	Output:
 *		Returns false if the input has been given on a previous turn.
 *		Otherwise, returns true.
 */

bool Board::validateState(int input)
{
	if (numbersTaken_[input]) {
		std::cout << "Invalid input - " << input << " has been played already." 
					 << std::endl;
		return false;
	}

	return true;
}

/*
 * Function Board::validateState
 * Input:
 *		x - the value of the x coordinate for the player's input
 *		y - the value of the y coordinate for the player's input
 *	Process:
 *		Checks to see if the x- and y-coordinates given by the player has been
 *		used on a previous turn.
 *	Output:
 *		Returns false if the x- and y-coordinate have been given on a previous 
 *		turn. Otherwise, returns true.
 */

bool Board::validateState(int x, int y)
{
	if (spacesTaken_[x][y]) {
		std::cout << "Invalid location - A number has been played at (" << x << ", " 
					 << y << ") already." << std::endl;
		return false;
	}

	return true;
}

/*
 * Function display
 * Input:
 *		none
 *	Process:
 *		none
 *	Output:
 *		Displays the current state of the board to the console using the board_
 *		array.
 */

void Board::display()
{
	for (int row = 0; row < GRID_SIZE_; row++) {
		std::cout << board_[row][0];
		for (int col = 1; col < GRID_SIZE_; col++)   // prints a | in between the columns
			std::cout << " | " << board_[row][col];
		if (row < GRID_SIZE_ - 1) 
			std::cout << "\n---------" << std::endl;   // prints a line in between rows
	}
	
	// print a bar as a visual divider of each "turn"
	std::cout << "\n_______________________________________________________________"
				 << std::endl;
}

/*
 * Function checkForWin
 * Input:
 *		x - the value of the x coordinate for the player's input
 *		y - the value of the y coordinate for the player's input
 *		input - the value of the number placed on the board by the player
 *	Process:
 *		Checks the rows, columns, and diagonals (if applicable) that contain
 *		the most recently played number to see if any of them sum to 15. If so,
 *		the player has won!
 *	Output:
 *		Returns true if any relevant row, column or diagonal sums to 15.
 *		Returns false otherwise.
 */

bool Board::checkForWin(int x, int y, int input)
{
	// check if the row containing the input sums to 15
	int rowSum = 0;
	for (int col = 0; col < GRID_SIZE_; col++)
		rowSum += board_[x][col];
	if (rowSum == 15) 
		return true;

	// checks if the column containing the input sums to 15
	int colSum = 0;
	for (int row = 0; row < GRID_SIZE_; row++)
		colSum += board_[row][y];
	if (colSum == 15) 
		return true;
	
	// checks if the backward diagonal (\) containing the input sums to 15
	if (x == y) {  // check if the input is in the back diagonal
		int backSlashSum = 0;
		for (int cell = 0; cell < GRID_SIZE_; cell++)
			backSlashSum += board_[cell][cell];
		if (backSlashSum == 15) 
			return true;
	}
	
	// checks if the forward diagonal (/) containing the input sums to 15
	if (x + y == GRID_SIZE_ - 1) {   // check if the input is in the forward diagonal
		int forwardSlashSum = 0;
		for (int cell = 0; cell < GRID_SIZE_; cell++)
			forwardSlashSum += board_[cell][GRID_SIZE_ - 1 - cell];
		if (forwardSlashSum == 15) 
			return true;
	}

	return false;   // return false if none of the above cases sum to 15
}
	
