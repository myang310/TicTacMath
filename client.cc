// Ming Yang

#include <iostream>
#include "board.h"

/*
 * Function Board::play
 * Input:
 *		currentPlayer - the current player number
 *	Process:
 *		Prompts the current player to input the number that they wish to play
 *		as well as the x- and y-coordinate for the number to be played at.
 *		Calls upon the validateInput functions to confirm that the values
 *		inputted are valid. If all inputs are valid, updates the spacesTaken_,
 *		numbersTaken_ and board_ arrays with the new input.
 *	Output:
 *		Returns the result of the function checkForWin
 *			True if the win condition is met
 *			False if the win condition is unmet
 */

bool Board::play(bool currentPlayer) 
{
	int input;
	int x, y;

	// request for a number to be played (input)
	std::cout << "\nPlayer # " << currentPlayer + 1 << "'s turn" << std::endl;
	std::cout << "Please enter the number you'd like to play: ";
	std::cin >> input;
	// checks for valid input;re-prompt for new input until valid 
	while (!validateInput(input) || !validateState(input)) {
		std::cout << "Please try again.\n" << std::endl;
		std::cout << "Please enter the number you'd like to play: ";
		std::cin >> input;
	}

	// requests for the x- and y-coordinates of input
	std::cout << "Please enter the x coordinate for your number (from 0-" 
				 << GRID_SIZE_ - 1 << "): ";
	std::cin >> x;
	std::cout << "Please enter the y coordinate for your number (from 0-" 
				 << GRID_SIZE_ - 1 << "): ";
	std::cin >> y;
	// checks for valid x- and y -coordinates;re-prompt for new x and y until valid 
	while (!validateInput(x, y) || !validateState(x,y)) {
		std::cout << "Please try again.\n" << std::endl;
		std::cout << "Please enter the x coordinate for your number (from 0-" 
					 << GRID_SIZE_ - 1 << "): ";
		std::cin >> x;
		std::cout << "Please enter the y coordinate for your number (from 0-" 
					 << GRID_SIZE_ - 1 << "): ";
		std::cin >> y;
	}
	std::cout << std::endl;
	
	// updates the arrays with the input from user (x, y and input)
	spacesTaken_[x][y] = true;
	numbersTaken_[input] = true;
	board_[x][y] = input;

	return !checkForWin(x, y, input);
}

/*
 * Function Board::validateInput
 * Input:
 *		x - the value of the x coordinate for the player's input
 *		y - the value of the y coordinate for the player's input
 *	Process:
 *		Checks the input for the x- and y-coordinates are valid, i.e. they are
 *		between 0 and 9.
 *	Output:
 *		Returns true if the x- and y-coordinates are valid. Returns false
 *		otherwise.
 */

bool Board::validateInput(int x, int y)
{
	// if x is less than 0 or greater than the board's dimensions, print error message
	if (x < 0 || x > GRID_SIZE_ - 1) {
		std::cout << "Invalid x coordinate - " << x << " is not between 0 to " 
					 << GRID_SIZE_ - 1 << "." << std::endl;
		return false;
	}

	// if y is less than 0 or greater than the board's dimensions, print error message
	if (y < 0 || y > GRID_SIZE_ - 1) {
		std::cout << "Invalid y coordinate - " << y << " is not between 0 to " 
					 << GRID_SIZE_ - 1 <<"." << std::endl;
		return false;
	}

	return true;
}

/*
 * Function Board::validateInput
 * Input:
 *		input - the value of the number to be placed on the board by the player
 * Process:
 *		Checks that the number to be played is valid, i.e. it is between 0 and 9.
 *	Output:
 *		Returns true if the number is valid. Returns false otherwise.
 */ 

bool Board::validateInput(int input)
{
	// if input is not a legal number (legal numbers are 1-9), print error message
	if (input < 1 || input > 9) {
		std::cout << "Invalid input - " << input << " is not between 1 and 9." 
					 << std::endl;
		return false;
	}
	
	return true;
}

