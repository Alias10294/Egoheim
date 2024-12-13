#include "../../includes/MenuElements/Button.h"
#include "../../includes/Game.h"
#include <iostream>

Button::Button(SDL_Texture* texture, int x, int y, int w, int h)
	: m_texture(texture)
{
	std::pair<int, int> windowCoeffs = Game::getWindowCoeffs();
	m_rect = SDL_Rect
	{
		windowCoeffs.first * x,
		windowCoeffs.second * y,
		windowCoeffs.first * w,
		windowCoeffs.second * h
	};
}
Button::~Button()
{
	SDL_DestroyTexture(m_texture);
}

void Button::Render(SDL_Renderer* renderer)
{
	if (m_texture)
		SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
}