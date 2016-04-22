// Ming Yang

class Board;

#ifndef PLAY_H
#define PLAY_H

class Play {
	public:
		static Play* newGame();  // memory is freed in main
	   ~Play();
		Play(Play &game);
		Play operator=(const Play& right);
		bool playing();
		void updateTurn();
		void updatePlayer();
		void printRules() const;

	private:
		Play();
		int turns;	// how many turns in the game has elapsed so far
		int currentPlayer;  // either 1 or 2
		Board* board;

		void display() const;
		int  getIntegerInput() const;					// ensures an integer value is given by user
		bool isValidNumber(int input) const;		// valid number between 1 and 9	
		bool isUsedNumber(int input) const;	
		bool isValidSquare(int x, int y) const;	// valid coordinates between 0 and 2
		bool isUsedSquare(int x, int y) const;
		bool checkForWin(int x, int y, int input) const;
};

#endif
