#include "Game.h"
#include <cstdlib>
#include <ctime>

int main() {
	srand((int) time(0));
	Game game;
	game.run();
	return 0;
}

