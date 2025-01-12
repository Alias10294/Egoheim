#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <SDL2\SDL.h>

class ResourceManager
{
private:
	SDL_Renderer* m_renderer;

public:
	ResourceManager();
	~ResourceManager();

	void Init(SDL_Renderer* renderer);
	SDL_Texture* LoadTexture(const char* file);
};

#endif RESOURCEMANAGER_H