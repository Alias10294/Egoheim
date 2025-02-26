#ifndef GAME_HPP
#define GAME_HPP

#include <memory>

#include "SDLContext.hpp"
#include "game_systems/input/InputManager.hpp"

class Game
{
public:
    Game(const SDLContext& context);
    ~Game();

    void Run();
    
private:
    std::unique_ptr<SDLContext> m_sdlContext;
    
    EventDispatcher m_eventDispatcher;
    InputManager m_inputManager;

};

#endif