#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "Structs.h"

class AnimatedTexture
{
private:
	SDL_Texture* m_textures;
	SDL_Rect m_currentRect;
	std::vector<float> m_frameTimes;
	struct CurrentFrameInfo { int i; float time; } m_currentFrameInfo;
	struct UpdateRythm { bool autonomous; int increment; } m_updateRythm;

public:
	AnimatedTexture(SDL_Texture* textures, const int nbFrames, const float frameTimes[], bool autonomy = true);
	~AnimatedTexture();

	void StartAnimation();
	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer, SDL_Rect* dstRect);
};

#endif ANIMATEDTEXTURE_H
