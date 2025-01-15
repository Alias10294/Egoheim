#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameManagers/ResourceManager.h"
#include "EventHandling/InputManager.h"
#include "GameManagers/SceneManager.h"
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

	bool Init();
	void Run();
	void Quit();

	static const WindowCoeffs GetWindowCoeffs();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	static WindowCoeffs s_windowCoeffs;

	ResourceManager m_resourceManager;
	InputManager m_inputManager;
	SceneManager m_sceneManager;
};

#endif GAME_H