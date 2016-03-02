// Ming Yang

#ifndef BOARD_H
#define BOARD_H

#include <iostream>

/* 
 * Class Board:
 *		Contains all the necessary member functions related to playing the board game 
 *		TicTacMath, including initialize, play and display. It also holds all the 
 *		relevant member variables to keep track of the board's state, numbers played, 
 *		and positions that have been taken.
 */

class Board {
	public:
		void initialize();
		void printRules();
		bool play(bool currentPlayer);
		void display();

	private:
		static const int GRID_SIZE_ = 3;   // dimensions of the game board
		int board_[GRID_SIZE_][GRID_SIZE_];   // tracks the numbers played
		bool spacesTaken_[GRID_SIZE_][GRID_SIZE_];   // tracks the spaces used
		bool numbersTaken_[GRID_SIZE_ * GRID_SIZE_ + 1];   // tracks the numbers used
			
		bool validateInput(int x, int y);
		bool validateInput(int input);
		bool validateState(int x, int y);
		bool validateState(int input);
		bool checkForWin(int x, int y, int input);
};	

#endif


