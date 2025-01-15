#include <iostream>
#include "../includes/Game.h"

WindowCoeffs Game::s_windowCoeffs = { 0, 0 };
Font Game::s_bigFont = Font();

Game::Game()
	: m_window(nullptr), m_renderer(nullptr), m_sceneManager(), m_resourceManager()
{ }
Game::~Game()
{ }

bool Game::Init()
{
	// Initialize SDL
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
	SDL_GetWindowSize(m_window, &s_windowCoeffs.w, &s_windowCoeffs.h);
	s_windowCoeffs.w /= WINDOW_WIDTH;
	s_windowCoeffs.h /= WINDOW_HEIGHT;

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

	// Initialize components
	s_bigFont.Init(m_renderer, BIGFONT_LETTERS, BIGFONT_WIDTHS, BIGFONT_SPACE, "BigFont");

	m_resourceManager.Init(m_renderer);
	m_inputManager.Init();
	m_sceneManager.Init(m_resourceManager, m_inputManager);
	return true;
}
void Game::Run()
{
	m_sceneManager.RunScene(m_renderer);
}
void Game::Quit()
{
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		m_window = nullptr;
	}
	if (m_renderer)
	{
		SDL_DestroyRenderer(m_renderer);
		m_renderer = nullptr;
	}
	SDL_Quit();
}

const WindowCoeffs Game::GetWindowCoeffs()
{
	return s_windowCoeffs;
}