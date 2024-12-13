#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Scenes/SceneManager.h"
#include "Utils/Font.h"
#include "Utils/Structs.h"

class Game
{
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	static WindowCoeffs m_windowCoeffs;

public:
	static Font s_bigFont;

	Game();
	~Game();

	static WindowCoeffs GetWindowCoeffs();

	bool Start();
	void Run();
	void End();
};

#endif GAME_H