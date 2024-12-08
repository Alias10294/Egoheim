#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <unordered_map>
#include "SDL.h"

class Font
{
private:
	int m_letterHeight;
	std::unordered_map<char, int> m_letterWidths;
	std::unordered_map<char, SDL_Texture*> m_letterTextures;
	int m_spaceBetweenLetters;

public:
	Font();
	~Font() = default;

	const int GetLetterHeight() const;
	const int GetLetterWidth(char c);
	const int GetLetterSpace() const;
	const void Start(SDL_Renderer* renderer, const char* letters, const int spaceBetweenLetters, const char* folderPath);
	const void RenderText(SDL_Renderer* renderer, const char* letters, SDL_Rect* rect);
};

#endif FONT_H