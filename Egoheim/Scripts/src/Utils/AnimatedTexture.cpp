#include "../../includes/Utils/AnimatedTexture.h"
#include "../../includes/Game.h"

AnimatedTexture::AnimatedTexture(SDL_Texture* textures, const int nbFrames, const float frameTimes[], bool autonomy)
	: m_textures(textures), m_currentRect{ 0, 0, 0, 0 }, m_currentFrameInfo { 0, 0.0 }
{
	SDL_QueryTexture(textures, NULL, NULL, &m_currentRect.w, &m_currentRect.h);
	m_currentRect.w /= nbFrames;

	for (int i = 0; i < nbFrames; i++)
		m_frameTimes.emplace_back(frameTimes[i]);

	m_updateRythm = { autonomy, autonomy ? 1 : 0 };
}
AnimatedTexture::~AnimatedTexture()
{
	SDL_DestroyTexture(m_textures);
}

void AnimatedTexture::StartAnimation()
{
	if (!m_updateRythm.autonomous)
		m_updateRythm.increment = m_currentFrameInfo.i == 0 ? 1 : -1;
}
void AnimatedTexture::Update(float deltaTime)
{
	m_currentFrameInfo.time += deltaTime;

	while (m_currentFrameInfo.time >= m_frameTimes[m_currentFrameInfo.i])
	{
		if (m_updateRythm.increment != 0) 
		{
			m_currentFrameInfo.i = (m_currentFrameInfo.i + m_updateRythm.increment) % m_frameTimes.size();
			m_currentFrameInfo.time -= m_frameTimes[m_currentFrameInfo.i];
			m_currentRect.x = m_currentRect.w * m_currentFrameInfo.i;
		}
		if (!m_updateRythm.autonomous)
		{
			if (m_updateRythm.increment > 0 && m_currentFrameInfo.i == m_frameTimes.size())
				m_updateRythm.increment = 0;
			if (m_updateRythm.increment < 0 && m_currentFrameInfo.i == 0)
				m_updateRythm.increment = 0;
		}
	}
}
void AnimatedTexture::Render(SDL_Renderer* renderer, SDL_Rect* dstRect)
{
	const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();

	if (m_textures)
	{
		dstRect->w = m_currentRect.w * windowCoeffs.w;
		dstRect->h = m_currentRect.h * windowCoeffs.h;
		SDL_RenderCopy(renderer, m_textures, &m_currentRect, dstRect);
	}
}