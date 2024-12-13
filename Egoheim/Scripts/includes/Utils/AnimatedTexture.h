#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Structs.h"

class AnimatedTexture
{
private:
	WindowCoeffs m_windowCoeffs;
	SDL_Texture* m_textures;
	SDL_Rect m_currentRect;
	std::vector<float> m_frameTimes;
	std::pair<float, int> m_currentFrameTime;


public:
	AnimatedTexture(SDL_Texture* textures, const int nbFrames, const float frameTimes[]);
	~AnimatedTexture();

	void UpdateFrame(float deltaTime);
	void Render(SDL_Renderer* renderer, SDL_Rect* dstRect);
};

#endif ANIMATEDTEXTURE_H
