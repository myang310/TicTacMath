// Ming Yang

#include "board.h"
#include "play.h"
#include <iostream>

Play* 
Play::newGame() {
	Play* game = new Play();
	return game;
}

Play::Play() {
	turns = 0;
	currentPlayer = 1;
	board = Board::setup();
}

Play::~Play() {
	delete board;
	board = NULL;
}

bool 
Play::playing() {
	int input;		// user-given number to be played onto board
	int x, y;		// user-given coordinates for the input

	// request for a number to be played (input)
	std::cout << "\nPlayer # " << currentPlayer << "'s turn" << std::endl;
	std::cout << "Please enter the number you'd like to play: ";
	
	input = getIntegerInput();
	while (!isValidNumber(input) || isUsedNumber(input)) {
		if (!isValidNumber(input)) {
			std::cout << "Input of " << input << " is not between 1 and 9.\n" << 
					"Please enter a number between 1 and 9: ";
		}else {
			std::cout << "The number " << input << " has been used.\n" << 
					"Please try another number between 1 and 9: ";
		}
		
		input = getIntegerInput();
	}
	
	// requests for the x- and y-coordinates of input
	std::cout << "Please enter the x coordinate for your number (from 0-" 
				 << board->getDimension() - 1 << "): ";
	x = getIntegerInput();

	std::cout << "Please enter the y coordinate for your number (from 0-" 
				 << board->getDimension() - 1 << "): ";
	y = getIntegerInput();

	// checks for valid x- and y -coordinates; re-prompt for new x and y until valid 
	while (!isValidSquare(x, y) || isUsedSquare(x, y)) {
		if (!isValidSquare(x, y)) {
			std::cout << "The coordinates given were not between 0 and " << 
					board->getDimension() - 1 << "." << std::endl;
		}else {
			std::cout <<"The coordinates given have previously been used." 
					<< std::endl;
		}
		std::cout << "Please try again.\n" << std::endl;
		
		std::cout << "Please enter the x coordinate for your number (from 0-" 
				 << board->getDimension() - 1 << "): ";
		x = getIntegerInput();
		
		std::cout << "Please enter the y coordinate for your number (from 0-" 
				 << board->getDimension() - 1 << "): ";
		y = getIntegerInput();
	}
	std::cout << std::endl;
	
	// updates the arrays with the input from user (x, y and input)
	board->setSquare(x, y, input);	
	
	// display updated board to user
	display();
	
	bool continuePlaying = true;
	if (checkForWin(x, y, input)) {
		std::cout << "\nCongratulations player " << currentPlayer
			<< ", you win!" << std::endl;
		continuePlaying = false;
	}else if (turns == 9) {
		std::cout << "\nIt's a tie! Good game everyone." << std::endl;
		continuePlaying = false;
	}

	return continuePlaying;
}

void 
Play::updateTurn() {
	turns++;
}

void 
Play::updatePlayer() {
	currentPlayer = 3 - currentPlayer;	// updates player to 1, 2, 1, 2, ...
}

void 
Play::printRules()
{
	std::cout << "\nTic-Tac-Math is a lot like Tic-Tac-Toe. "
		<< "The game is played on\n"
		<< "a 3x3 grid; players take turns marking one cell "
		<< "at a time. The\n"
		<< "difference is that instead of placing Xs and Os "
		<< "on the grid,\n"
		<< "players place the numbers 1 to 9. And instead of "
		<< "trying to make\n"
		<< "a row, column, or diagonal filled with 3 Xs or 3 "
		<< "Os, the players\n"
		<< "try to make a row, column, or diagonal whose cells "
		<< "sum to 15.\n"
		<< "One wrinkle: each number can only be placed ONCE." 
		<< std::endl;
}

void
Play::display() {
	int size = board->getDimension();

	std::cout << "\t   0   1   2\n" << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "\t" << i << "  " << board->getNumber(i, 0);
		
		// prints a | in between the columns
		for (int j = 1; j < size; j++)   			
			std::cout << " | " << board->getNumber(i, j);

		if (i <  - 1) {
			// prints a line in between rows
			std::cout << "\n\t   ---------" << std::endl;
		}else {
			std::cout << "\n" << std::endl;
		}
	}		

	// print a bar as a visual divider of each "turn"
	std::cout << "\n__________________________________" <<
		"_____________________________" << std::endl;
}

int
Play::getIntegerInput() {
	int input;
	while(!(std::cin >> input)) {
		std::cout << "Not an integer! Please enter a valid integer: ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	return input;
}

bool
Play::isValidNumber(int input) {
	// checking if input is a valid number from 1 to 9
	if (input < 1 || input > 9) {
		return false;
	}
	
	return true;
}

bool
Play::isUsedNumber(int input) {
	if (board->isUsedNumber(input)) {
		return true;
	}
	
	return false; 
}

bool
Play::isValidSquare(int x, int y) {
	// checking if the x and y are within the board's dimensions
	if (x < 0 || x > board->getDimension() - 1 ||
			y < 0 || y > board->getDimension() - 1) {
		return false;
	}

	return true;
}

bool
Play::isUsedSquare(int x, int y) {
	if (board->getNumber(x, y)) {
		return true;
	}
	
	return false;
}

bool
Play::checkForWin(int x, int y, int input) {
	int size = board->getDimension();
	
	// check if the row containing the input sums to 15
	int rowSum = 0;
	bool zeroInRow = false;
	
	for (int j = 0; j < size; j++) {
		rowSum += board->getNumber(x, j);
		if (board->getNumber(x, j) == 0) {
			zeroInRow = true;
			break;
		}
	}

	if (rowSum == 15 && !zeroInRow)
		return true;

	// checks if the column containing the input sums to 15
	int colSum = 0;
	bool zeroInCol = false;
	for (int i = 0; i < size; i++) {
		colSum += board->getNumber(i, y);
	
		if (board->getNumber(i, y) == 0)	{
			zeroInCol = true;
			break;
		}
	}	
	if (colSum == 15 && !zeroInCol) 
		return true;
	
	// checks if the backward diagonal (\) containing the input sums to 15
	if (x == y) { 
		int backSlashSum = 0;
		bool zeroInBackSlash = false;
		
		for (int k = 0; k < size; k++) {
			backSlashSum += board->getNumber(k, k);
			if (board->getNumber(k, k) == 0) {
				zeroInBackSlash = true;
				break;
			}
		}
		
		if (backSlashSum == 15 && !zeroInBackSlash) 
			return true;
	}
	
	// checks if the forward diagonal (/) containing the input sums to 15
	if (x + y == size - 1) {   		
		int forwardSlashSum = 0;
		bool zeroInForwardSlash = false;
	
		for (int k = 0; k < size; k++) {
			forwardSlashSum += board->getNumber(k, size-k-1);
			if (board->getNumber(k, size-k-1) == 0) {
				zeroInForwardSlash = true;
				break;
			}
		}
	
		if (forwardSlashSum == 15 && !zeroInForwardSlash) 
			return true;
	}

	return false;   // return false if none of the above cases sum to 15
}
