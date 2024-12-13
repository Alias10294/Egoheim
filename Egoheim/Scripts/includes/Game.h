#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Scenes/SceneManager.h"
#include "Font.h"

class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	static std::pair<int, int> m_windowCoeffs;

public:
	static Font s_bigFont;

	Game();
	~Game();

	static std::pair<int, int> getWindowCoeffs();

	bool Start();
	void Run();
	void End();
};

#endif GAME_H