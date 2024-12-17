#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include "AnimatedTextureInfo.h"

class AnimatedTexture
{
private:
	SDL_Texture* m_textures;
	SDL_Rect m_currentRect;
	std::vector<float> m_frameTimes;
	struct CurrentFrameInfo { int i; float time; } m_currentFrameInfo;
	struct UpdateRythm { bool autonomous; int increment; } m_updateRythm;

public:
	AnimatedTexture(SDL_Texture* textures, AnimatedTextureInfo textureInfo);
	~AnimatedTexture();

	void React();
	void Update(const float deltaTime, const bool desiredState = true);
	void Render(SDL_Renderer* renderer, SDL_Rect* rect);
};

#endif ANIMATEDTEXTURE_H
