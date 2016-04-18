// Ming Yang

#ifndef BOARD_H
#define BOARD_H

class Board {
	public:
		static Board* setup();
		int getNumber(int x, int y);
		int getDimension();
		void setSquare(int x, int y, int input);	// updates board, squaresUsed and numbersUsed
		bool isUsedNumber(int number);

	private:
		Board();
		
		const static int DIMENSION = 3;
		int board[DIMENSION][DIMENSION];
		bool squaresUsed[DIMENSION][DIMENSION];
		bool numbersUsed[DIMENSION * DIMENSION + 1];
};

#endif
