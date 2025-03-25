#include "Game.hpp"

Game::Game(const SDLContext& context)
    : m_sdlContext(std::make_unique<SDLContext>(context)), 
    m_context(InputContext::MENU), 
    m_eventDispatcher(), 
    m_inputManager(m_context, m_eventDispatcher),
    m_renderingManager(), 
    m_resourceManager(m_sdlContext->GetRenderer()), 
    m_sceneManager()
{}
Game::~Game()
{}

void Game::Run()
{
    m_inputManager.ProcessInputs();
}
