#ifndef ANIMATEDTEXTURE_H
#define ANIMATEDTEXTURE_H

#include <SDL2/SDL.h>
#include <vector>

class AnimatedTexture
{
private:
	SDL_Texture* m_textures;
	SDL_Rect m_rect;
	int m_nbFrames;
	std::vector<float> m_frameTimes;


public:
	AnimatedTexture(SDL_Texture* textures, SDL_Rect rect, int nbFrames, float frameTimes[]);
	~AnimatedTexture();

	void UpdateFrame(float deltaTime);
	void Render(SDL_Renderer* renderer);
};

#endif ANIMATEDTEXTURE_H
