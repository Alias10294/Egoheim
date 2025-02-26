#include "Game.hpp"

Game::Game(const SDLContext& context)
    : m_sdlContext(std::make_unique<SDLContext>(context)), 
    m_eventDispatcher(), 
    m_inputManager(m_eventDispatcher)
{
    SDL_Log("game launched\n");
}
Game::~Game()
{}

void Game::Run()
{
    m_inputManager.ProcessInput();
}
