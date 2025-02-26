#define SDL_MAIN_HANDLED

#include "Game.hpp"

int main(int argc, char* argv[])
{
    SDLContext context;
    Game game(context);
    game.Run();
    return 0;
}