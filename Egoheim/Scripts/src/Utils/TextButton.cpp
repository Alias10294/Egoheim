#include "../../includes/Utils/TextButton.h"
#include "../../includes/Game.h"


TextButton::TextButton(SDL_Texture* texture, const char* text, int x, int y, int w, int h, std::function<void()> action)
	: Button(texture, x, y, w, h, action), m_text(text), m_textRect{ NULL, NULL, NULL, NULL }
{
	const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();

	m_textRect.y = ((y + h / 2) - (Game::s_bigFont.GetLetterHeight() / 2)) * windowCoeffs.h + windowCoeffs.h;

	int wText = Game::s_bigFont.GetLetterWidth(m_text[0]);
	int i = 0;
	while (m_text[++i] != '\0')
		wText += Game::s_bigFont.GetLetterSpace() + Game::s_bigFont.GetLetterWidth(m_text[i]);
	m_textRect.x = ((x + w / 2) - (wText / 2)) * windowCoeffs.w - windowCoeffs.w;
}
TextButton::~TextButton()
{
	delete m_text;
}

void TextButton::Render(SDL_Renderer* renderer)
{
	if (m_texture)
		SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
	Game::s_bigFont.RenderText(renderer, m_text, &m_textRect);
}