#include "../includes/Font.h"
#include "../includes/Game.h"
#include <format>
#include <SDL2/SDL_image.h>

Font::Font()
	: m_letterTextures(nullptr), m_spaceBetweenLetters(0)
{ }

const int Font::GetLetterHeight()
{
	return m_letterRects['0'].h;
}
const int Font::GetLetterWidth(char c)
{
	return m_letterRects[c].w;
}
const int Font::GetLetterSpace() const
{ 
	return m_spaceBetweenLetters;
}

const void Font::Start(
	SDL_Renderer* renderer, 
	const char* letters, 
	const int letterWidths[],  
	const int spaceBetweenLetters,  
	const char* folderPath)
{
	m_windowCoeffs = Game::getWindowCoeffs();
	m_letterTextures = IMG_LoadTexture(renderer, std::format("Assets/Fonts/{}.png", folderPath).c_str());

	int i = -1;
	int x = 0;
	int h;
	SDL_QueryTexture(m_letterTextures, NULL, NULL, NULL, &h);
	while (letters[++i] != '\0')
	{
		m_letterRects[letters[i]] = SDL_Rect(x, 0, letterWidths[i], h);
		x += letterWidths[i];
	}
	m_spaceBetweenLetters = spaceBetweenLetters;
}
const void Font::RenderText(SDL_Renderer* renderer, const char* letters, SDL_Rect* rect)
{
	int i = -1;
	SDL_Rect dstRect = *rect;
	while (letters[++i] != '\0')
	{
		SDL_Rect srcRect = m_letterRects[letters[i]];
		
		dstRect.w = srcRect.w * m_windowCoeffs.first;
		dstRect.h = srcRect.h * m_windowCoeffs.second;
		SDL_RenderCopy(renderer, m_letterTextures, &srcRect, &dstRect);
		dstRect.x += dstRect.w + m_spaceBetweenLetters * m_windowCoeffs.first;
	}
}