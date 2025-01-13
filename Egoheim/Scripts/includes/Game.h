#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameManagers/SceneManager.h"
#include "GameManagers/ResourceManager.h"
#include "Utils/Font.h"
#include "Utils/WindowCoeffs.h"

constexpr const char* GAME_TITLE = "Egoheim";

constexpr int WINDOW_WIDTH = 480;
constexpr int WINDOW_HEIGHT = 270;

class Game
{
public:
	static Font s_bigFont;

	Game();
	~Game();

	static const WindowCoeffs GetWindowCoeffs();

	void Run();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	static WindowCoeffs s_windowCoeffs;

	SceneManager m_sceneManager;
	ResourceManager m_resourceManager;
};

#endif GAME_H