// Ming Yang

#include <iostream>
#include "play.h"
#include "board.h"

void promptNewGame(std::string &);

int main() {
	bool newGame = true;
	while (newGame) {
		Play* game = Play::newGame();
		game->printRules();
		while (game->playing()) {
			game->updateTurn();
			game->updatePlayer();
		}

		delete game;
		game = NULL;

		std::string response = "";
		promptNewGame(response);
		if (response == "no")
			newGame = false;
	}	
	std::cout << "Thanks for playing!" << std::endl;
}

void promptNewGame(std::string& anotherGame) {
	while (anotherGame != "yes" && anotherGame != "no") {
		std::cout << "Would you like to play another game? Please enter [yes] or [no]: ";
		std::cin >> anotherGame;
		if (anotherGame != "yes" && anotherGame != "no")
			std::cout << "Invalid entry. Please try again." << std::endl;
	}
}
