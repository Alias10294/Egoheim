#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <unordered_map>
#include <SDL2/SDL.h>

constexpr const char* BIGFONT_LETTERS = "0123456789abcdefghijklmnopqrstuvwxyz";
constexpr const int BIGFONT_WIDTHS[] = { 9,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,5,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 };
constexpr int BIGFONT_SPACE = 2;

constexpr const char* SMALLFONT_LETTERS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz,;:!?./";
constexpr int SMALLFONT_SPACE = 1;

class Font
{
private:
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