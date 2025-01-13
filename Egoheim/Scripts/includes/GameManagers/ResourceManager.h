#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL2\SDL.h>

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	void Init(SDL_Renderer* renderer);
	void Quit();

	SDL_Texture* LoadTexture(const char* file);

private:
	SDL_Renderer* m_renderer;
};

#endif RESOURCEMANAGER_H