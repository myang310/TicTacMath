// Ming Yang

#include "board.h"
#include <iostream>

Board*
Board::setup() {
	Board* gameBoard = new Board();
	return gameBoard;
}

Board::Board() {
	for (int i = 0; i < DIMENSION; i++) {
		board[i] = new int[DIMENSION];
		squaresUsed[i] = new bool[DIMENSION];
	}
	numbersUsed = new bool [NUMCOUNT];

	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			board[i][j] = 0;
			squaresUsed[i][j] = false;
		}
	}
	
	for (int i = 0; i < NUMCOUNT; i++) {
		numbersUsed[i] = false;
	}
}

Board::~Board() {
	for (int i = 0; i < DIMENSION; i++) {
		delete board[i];
		board[i] = NULL;
		delete squaresUsed[i];
		squaresUsed[i] = NULL;
	}
	delete [] numbersUsed;
	numbersUsed = NULL;
}

Board::Board(Board& old) {
	for (int i = 0; i < DIMENSION; i++) {
		board[i] = new int[DIMENSION];
		squaresUsed[i] = new bool[DIMENSION];
		for (int j = 0; j < DIMENSION; j++) {
			board[i][j] = old.board[i][j];
			squaresUsed[i][j] = old.squaresUsed[i][j];
		}
	}

	numbersUsed = new bool[NUMCOUNT];
	for (int i = 0; i < NUMCOUNT; i++) {
		numbersUsed[i] = old.numbersUsed[i];
	}
}

Board
Board::operator=(const Board& right) {	
	for (int i = 0; i < DIMENSION; i++) {
		delete board[i];
		board[i] = NULL;
		delete squaresUsed[i];
		squaresUsed[i] = NULL;
	}
	delete numbersUsed;
	numbersUsed = NULL;
	
	for (int i = 0; i < DIMENSION; i++) {
		board[i] = new int[DIMENSION];
		squaresUsed[i] = new bool[DIMENSION];
		for (int j = 0; j < DIMENSION; j++) {
			board[i][j] = right.board[i][j];
			squaresUsed[i][j] = right.squaresUsed[i][j];
		}
	}

	numbersUsed = new bool[NUMCOUNT];
	for (int i = 0; i < NUMCOUNT; i++) {
		numbersUsed[i] = right.numbersUsed[i];
	}

	return *this;
}

int
Board::getNumber(int x, int y) const {
	return board[x][y];
}

int
Board::getDimension() const {
	return DIMENSION;
}

void
Board::setSquare(int x, int y, int input) {
	board[x][y] = input;
	squaresUsed[x][y] = true;
	numbersUsed[input] = true;
}

bool
Board::isUsedNumber(int number) const {
	return numbersUsed[number];
}
