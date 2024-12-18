#include "../../includes/Utils/AnimatedTexture.h"
#include "../../includes/Game.h"

AnimatedTexture::AnimatedTexture(SDL_Texture* textures, AnimatedTextureInfo textureInfo, int direction)
	: m_textures(textures), m_increment(direction), m_currentFrameInfo{ 0, 0 }
{
	SDL_QueryTexture(textures, NULL, NULL, &m_currentRect.w, &m_currentRect.h);
	m_currentRect.w /= textureInfo.nbFrames;

	for (int i = 0; i < textureInfo.nbFrames; i++)
		m_frameTimes.emplace_back(textureInfo.frameTimes[i]);
}
AnimatedTexture::~AnimatedTexture()
{
	std::vector<int>().swap(m_frameTimes);
}

void AnimatedTexture::Update(const uint32_t deltaTimeMs)
{
	m_currentFrameInfo.timeMs += deltaTimeMs;

	while (m_currentFrameInfo.timeMs >= m_frameTimes[m_currentFrameInfo.i])
	{
		m_currentFrameInfo.i = (m_currentFrameInfo.i + m_increment) % (int)m_frameTimes.size();
		m_currentFrameInfo.timeMs -= m_frameTimes[m_currentFrameInfo.i];
		m_currentRect.x = m_currentRect.w * m_currentFrameInfo.i;
	}
}
void AnimatedTexture::UpdateReact(const uint32_t deltaTimeMs, const bool state)
{
	if (state && m_currentFrameInfo.i < m_frameTimes.size() - 1)
		m_increment = 1;
	if (!state && m_currentFrameInfo.i > 0)
		m_increment = -1;

	m_currentFrameInfo.timeMs += deltaTimeMs;

	while (m_currentFrameInfo.timeMs >= m_frameTimes[m_currentFrameInfo.i])
	{
		m_currentFrameInfo.i = (m_currentFrameInfo.i + m_increment) % (int)m_frameTimes.size();
		m_currentFrameInfo.timeMs -= m_frameTimes[m_currentFrameInfo.i];
		m_currentRect.x = m_currentRect.w * m_currentFrameInfo.i;

		if (m_increment > 0 && m_currentFrameInfo.i == m_frameTimes.size() - 1)
			m_increment = 0;
		if (m_increment < 0 && m_currentFrameInfo.i == 0)
			m_increment = 0;
	}
}

void AnimatedTexture::Render(SDL_Renderer* renderer, SDL_Rect* rect)
{
	if (m_textures)
	{
		const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();
		SDL_Rect dstRect = *rect;
		dstRect.w = m_currentRect.w * windowCoeffs.w;
		dstRect.h = m_currentRect.h * windowCoeffs.h;
		SDL_RenderCopy(renderer, m_textures, &m_currentRect, &dstRect);
	}
}