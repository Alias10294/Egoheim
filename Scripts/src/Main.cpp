#include <iostream>
#include "../includes/Game.h"

int main(int argc, char* argv[])
{
	Game game;
	if (game.Start())
	{
		game.Run();
		game.End();
	}
	return 0;
}