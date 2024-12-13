#include "../../includes/Utils/AnimatedTexture.h"
#include "../../includes/Game.h"

AnimatedTexture::AnimatedTexture(SDL_Texture* textures, const int nbFrames, const float frameTimes[])
	: m_textures(textures), m_currentRect{ 0, 0, 0, 0 }
{
	m_windowCoeffs = Game::getWindowCoeffs();

	SDL_QueryTexture(textures, NULL, NULL, &m_currentRect.w, &m_currentRect.h);
	m_currentRect.w /= nbFrames;

	for (int i = 0; i < nbFrames; i++)
		m_frameTimes.emplace_back(frameTimes[i]);
}
AnimatedTexture::~AnimatedTexture()
{
	SDL_DestroyTexture(m_textures);
}

void AnimatedTexture::UpdateFrame(float deltaTime)
{ }
void AnimatedTexture::Render(SDL_Renderer* renderer, SDL_Rect* dstRect)
{
	if (m_textures)
	{
		dstRect->w = m_currentRect.w * m_windowCoeffs.first;
		dstRect->h = m_currentRect.h * m_windowCoeffs.second;
		SDL_RenderCopy(renderer, m_textures, &m_currentRect, dstRect);
	}
}