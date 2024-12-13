#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <unordered_map>
#include <SDL2/SDL.h>

class Font
{
private:
	std::pair<int, int> m_windowCoeffs;
	std::unordered_map<char, SDL_Rect> m_letterRects;
	SDL_Texture* m_letterTextures;
	int m_spaceBetweenLetters;

public:
	Font();
	~Font() = default;

	const int GetLetterHeight();
	const int GetLetterWidth(char c);
	const int GetLetterSpace() const;

	const void Start(SDL_Renderer* renderer, const char* letters, const int letterWidths[], const int spaceBetweenLetters, const char* folderPath);
	const void RenderText(SDL_Renderer* renderer, const char* letters, SDL_Rect* rect);
};

#endif FONT_H