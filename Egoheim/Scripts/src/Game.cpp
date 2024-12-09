#include <iostream>
#include "../includes/Game.h"
#include "../includes/Constants.h"

std::pair<int, int> Game::m_windowCoeffs = { 0, 0 };
Font Game::m_bigFont = Font();

Game::Game()
	: m_window(nullptr), m_renderer(nullptr)
{ }
Game::~Game()
{ }

std::pair<int, int> Game::getWindowCoeffs()
{
	return m_windowCoeffs;
}

bool Game::Start()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cerr << "Initialization error of SDL: " << SDL_GetError() << std::endl;
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		std::cerr << "Initialization error of IMG:" << IMG_GetError() << std::endl;
		SDL_Quit();
		return false;
	}

	m_window = SDL_CreateWindow(
		GAME_TITLE,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP); // | SDL_WINDOW_FULLSCREEN_DESKTOP
	if (!m_window)
	{
		std::cerr << "Initialization error of window: " << SDL_GetError() << std::endl;
		IMG_Quit();
		SDL_Quit();
		return false;
	}
	SDL_GetWindowSize(m_window, &m_windowCoeffs.first, &m_windowCoeffs.second);
	m_windowCoeffs.first /= WINDOW_WIDTH;
	m_windowCoeffs.second /= WINDOW_HEIGHT;

	m_renderer = SDL_CreateRenderer(
		m_window,
		-1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!m_renderer)
	{
		std::cerr << "Initialization error of renderer: " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		IMG_Quit();
		return false;
	}

	m_bigFont.Start(
		m_renderer, 
		BIGFONT_LETTERS, 
		BIGFONT_SPACE, 
		"BigFont");

	return true;
}
void Game::Run()
{
	SceneManager sceneManager;
	sceneManager.RunScene(m_renderer);
}
void Game::End()
{
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	if(m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
	SDL_Quit();
}