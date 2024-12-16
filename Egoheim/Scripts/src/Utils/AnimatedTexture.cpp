#include "../../includes/Utils/AnimatedTexture.h"
#include "../../includes/Game.h"

AnimatedTexture::AnimatedTexture(SDL_Texture* textures, AnimatedTextureInfo textureInfo)
	: m_textures(textures), m_currentFrameInfo{ 0, 0.0f }
{
	SDL_QueryTexture(textures, NULL, NULL, &m_currentRect.w, &m_currentRect.h);
	m_currentRect.w /= textureInfo.nbFrames;

	for (int i = 0; i < textureInfo.nbFrames; i++)
		m_frameTimes.emplace_back(textureInfo.frameTimes[i]);

	m_updateRythm = { textureInfo.autonomy, textureInfo.autonomy ? 1 : 0 };
}
AnimatedTexture::~AnimatedTexture()
{
	std::vector<float>().swap(m_frameTimes);
}

void AnimatedTexture::StartAnimation()
{
	if (!m_updateRythm.autonomous)
		m_updateRythm.increment = m_currentFrameInfo.i == 0 ? 1 : -1;
}
void AnimatedTexture::Update(const float deltaTime)
{
	m_currentFrameInfo.time += deltaTime;

	while (m_currentFrameInfo.time >= m_frameTimes[m_currentFrameInfo.i])
	{
		if (m_updateRythm.increment != 0) 
		{
			m_currentFrameInfo.i = (m_currentFrameInfo.i + m_updateRythm.increment) % (int)m_frameTimes.size();
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