// Ming

#include "board.h"
#include <iostream>

Board*
Board::setup() {
	Board* gameBoard = new Board();
	return gameBoard;
};

Board::Board() {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			board[i][j] = 0;
			squaresUsed[i][j] = false;
		}
	}
	
	int numberOfNumbers = DIMENSION * DIMENSION + 1;
	for (int i = 0; i < numberOfNumbers; i++) {
		numbersUsed[i] = false;
	}
};

int
Board::getNumber(int x, int y) {
	return board[x][y];
};

int
Board::getDimension() {
	return DIMENSION;
};

void
Board::setSquare(int x, int y, int input) {
	board[x][y] = input;
	squaresUsed[x][y] = true;
	numbersUsed[input] = true;
};

bool
Board::isUsedNumber(int number) {
	return numbersUsed[number];
};

