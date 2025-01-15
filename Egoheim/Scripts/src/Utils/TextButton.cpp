#include "../../includes/Utils/TextButton.h"
#include "../../includes/Game.h"


TextButton::TextButton(
	SDL_Texture* textures, 
	const int nbFrames,
	const float* frameTimes,
	const char* text, 
	SDL_Rect rect, 
	std::function<void()> onClick)
	: Button(textures, nbFrames, frameTimes, rect, onClick), m_text(text), m_textRect{ NULL, NULL, NULL, NULL }
{
	const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();

	m_textRect.y = ((rect.y + rect.h / 2) - (Game::s_bigFont.GetLetterHeight() / 2)) * windowCoeffs.h + windowCoeffs.h;

	int wText = Game::s_bigFont.GetLetterWidth(m_text[0]);
	int i = 0;
	while (m_text[++i] != '\0')
		wText += Game::s_bigFont.GetLetterSpace() + Game::s_bigFont.GetLetterWidth(m_text[i]);
	m_textRect.x = ((rect.x + rect.w / 2) - (wText / 2)) * windowCoeffs.w - windowCoeffs.w;
}
TextButton::~TextButton()
{ }

void TextButton::Render(SDL_Renderer* renderer)
{
	m_texture.Render(renderer, &m_rect);
	Game::s_bigFont.RenderText(renderer, m_text, &m_textRect);
}