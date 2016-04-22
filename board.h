// Ming Yang

#ifndef BOARD_H
#define BOARD_H

class Board {
	public:
		static Board* setup();
		~Board();
		Board(Board& board);
		Board operator=(const Board& right);
		int getNumber(int x, int y) const;
		int getDimension() const;
		void setSquare(int x, int y, int input);	// updates board, squaresUsed and numbersUsed
		bool isUsedNumber(int number) const;

	private:
		Board();

		const static int DIMENSION = 3;
		const static int NUMCOUNT = DIMENSION * DIMENSION + 1;
		int* board[DIMENSION];
		bool* squaresUsed[DIMENSION];
		bool* numbersUsed;
};

#endif
