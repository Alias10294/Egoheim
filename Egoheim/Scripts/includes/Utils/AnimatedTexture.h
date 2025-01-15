#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

class AnimatedTexture
{
public:
	AnimatedTexture(SDL_Texture* textures, const int nbFrames, const float* frameTimes, int direction = 1);
	virtual ~AnimatedTexture();

	void Update(const uint32_t deltaTimeMs);
	void UpdateReact(const uint32_t deltaTimeMs, const bool state);
	void Render(SDL_Renderer* renderer, SDL_Rect* rect);

private:
	SDL_Texture* m_textures;
	SDL_Rect m_currentRect;
	std::vector<int> m_frameTimesMs;
	struct CurrentFrameInfo { int i; int timeMs; } m_currentFrameInfo;
	int m_increment;
};

#endif ANIMATEDTEXTURE_H
