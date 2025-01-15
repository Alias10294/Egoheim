#include <iostream>
#include "../includes/Game.h"

int main(int argc, char* argv[])
{
	Game game;
	if (game.Init())
	{
		game.Run();
		game.Quit();
	}
	return 0;
}