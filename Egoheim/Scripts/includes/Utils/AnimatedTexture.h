#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Structs.h"
#include "Constants.h"

class AnimatedTexture
{
private:
	SDL_Texture* m_textures;
	SDL_Rect m_currentRect;
	std::vector<float> m_frameTimes;
	struct CurrentFrameInfo { int i; float time; } m_currentFrameInfo;

public:
	AnimatedTexture(SDL_Texture* textures, const int nbFrames, const float frameTimes[]);
	~AnimatedTexture();

	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer, SDL_Rect* dstRect);
};

#endif ANIMATEDTEXTURE_H
