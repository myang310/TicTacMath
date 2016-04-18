// Ming Yang

class Board;

#ifndef PLAY_H
#define PLAY_H

class Play {
	public:
		static Play* newGame();  // memory is freed in main
	   ~Play();
		bool playing();
		void updateTurn();
		void updatePlayer();
		void printRules();

	private:
		Play();
		int turns;	// how many turns in the game has elapsed so far
		int currentPlayer;
		Board* board;

		void display();
		int  getIntegerInput();	 // ensures an integer value is given by user
		bool isValidNumber(int input);  // valid number between 1 and 9	
		bool isUsedNumber(int input);
		bool isValidSquare(int x, int y);  // valid coordinates between 0 and 2
		bool isUsedSquare(int x, int y);
		bool checkForWin(int x, int y, int input);
};

#endif
