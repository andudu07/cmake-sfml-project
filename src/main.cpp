#include "Game.h"
#include <cstdlib>
#include <ctime>

int main() {
	srand((int) time(0));
	
	Game& game = Game::getInstance();
	game.run();
	
	return 0;
}

