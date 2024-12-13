#include "../includes/AnimatedTexture.h"

AnimatedTexture::AnimatedTexture(SDL_Texture* textures, SDL_Rect rect, int nbFrames, float frameTimes[])
	: m_textures(textures), m_rect(rect), m_nbFrames(nbFrames)
{
	for (int i = 0; i < nbFrames; i++)
		m_frameTimes.emplace_back(frameTimes[i]);
}