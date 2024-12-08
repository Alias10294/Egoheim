#include "../../includes/Constants.h"
#include "../../includes/MenuElements/TextButton.h"
#include "../../includes/Game.h"


TextButton::TextButton(SDL_Texture* texture, const char* text, int x, int y, int w, int h)
	: Button(texture, x, y, w, h), m_text(text), m_textRect{ NULL, NULL, NULL, NULL }
{
	std::pair<int, int> windowCoeffs = Game::getWindowCoeffs();

	m_textRect.y = ((y + h / 2) - (Game::m_bigFont.GetLetterHeight() / windowCoeffs.second / 2)) * windowCoeffs.second + windowCoeffs.second;

	int wText = Game::m_bigFont.GetLetterWidth(m_text[0]);
	int i = 0;
	while (m_text[++i] != '\0')
		wText += Game::m_bigFont.GetLetterSpace() + Game::m_bigFont.GetLetterWidth(m_text[i]);
	m_textRect.x = ((x + w / 2) - (wText / windowCoeffs.first / 2)) * windowCoeffs.first - windowCoeffs.first;
}
TextButton::~TextButton()
{
	delete m_text;
}

void TextButton::Render(SDL_Renderer* renderer)
{
	if (m_texture)
		SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
	Game::m_bigFont.RenderText(renderer, m_text, &m_textRect);
}