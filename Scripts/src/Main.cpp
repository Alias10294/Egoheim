#include <iostream>
#include "../includes/Game.h"

int main(int argc, char* argv[])
{
    printf("new commit");
	Game game;
	if (game.Start())
	{
		game.Run();
		game.End();
	}
	return 0;
}