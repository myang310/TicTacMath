// Ming Yang

#ifndef PLAY_H
#define PLAY_H

class Board {
	public:
		static Board* setup();
		int getNumber(int x, int y);
		int getDimension();
		void setSquare(int x, int y, int input);	// updates board, squaresUsed and numbersUsed
		bool isUsedNumber(int number);

	private:
		Board();
		
		int dimension = 3;
		int board[dimension][dimension];
		bool squaresUsed[dimension][dimension];
		bool numbersUsed[dimension * dimension + 1];
}

#endif
