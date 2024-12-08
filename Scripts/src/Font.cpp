#include "../includes/Font.h"
#include "../includes/Game.h"
#include <format>
#include <SDL_image.h>

Font::Font()
	: m_letterHeight(0), m_spaceBetweenLetters(0)
{ }

const int Font::GetLetterHeight() const
{
	return m_letterHeight;
}
const int Font::GetLetterWidth(char c)
{
	return m_letterWidths[c];
}
const int Font::GetLetterSpace() const
{
	return m_spaceBetweenLetters;
}

const void Font::Start(
	SDL_Renderer* renderer, 
	const char* letters, 
	const int spaceBetweenLetters,  
	const char* folderPath)
{
	std::pair<int, int> windowCoeffs = Game::getWindowCoeffs();

	size_t nbLetters = 0;
	while (letters[nbLetters++] != '\0'); --nbLetters;
	for (int i = 0; i < nbLetters; i++)
	{
		m_letterTextures[letters[i]] = IMG_LoadTexture(
			renderer, 
			std::format(
				"Assets/Fonts/{}/{}_{}.png", 
				folderPath, 
				folderPath, 
				letters[i]).c_str());
		SDL_QueryTexture(m_letterTextures[letters[i]], NULL, NULL, &m_letterWidths[letters[i]], &m_letterHeight);
		m_letterWidths[letters[i]] *= windowCoeffs.first;
	}
	m_letterHeight *= windowCoeffs.second;
	m_spaceBetweenLetters = spaceBetweenLetters * windowCoeffs.first;
}
const void Font::RenderText(SDL_Renderer* renderer, const char* letters, SDL_Rect* rect)
{
	SDL_Rect tempRect = { rect->x, rect->y, m_letterWidths[0], m_letterHeight };
	size_t nbLetters = 0;
	while (letters[nbLetters++] != '\0'); --nbLetters;
	for (int i = 0; i < nbLetters; i++)
	{
		tempRect.w = m_letterWidths[letters[i]];
		if (m_letterTextures[letters[i]]) 
			SDL_RenderCopy(renderer, m_letterTextures[letters[i]], NULL, &tempRect);
		tempRect.x += m_letterWidths[letters[i]] + m_spaceBetweenLetters;
	}
}