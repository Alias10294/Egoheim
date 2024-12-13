#include "../../includes/Utils/Button.h"
#include "../../includes/Game.h"
#include <iostream>

Button::Button(SDL_Texture* texture, int x, int y, int w, int h, std::function<void()> action)
	: m_texture(texture), m_action(action)
{
	WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();
	m_rect = SDL_Rect
	{
		windowCoeffs.w * x,
		windowCoeffs.h * y,
		windowCoeffs.w * w,
		windowCoeffs.h * h
	};
}
Button::~Button()
{
	SDL_DestroyTexture(m_texture);
}

void Button::HandleEvents(const SDL_Event& event)
{
	if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
	{
		int x;
		int y;
		SDL_GetMouseState(&x, &y);
		bool isPressed = (
			m_rect.x <= x && x <= m_rect.x + m_rect.w &&
			m_rect.y <= y && y <= m_rect.y + m_rect.h );
		if (isPressed && m_action)
			m_action();
	}
}
void Button::Render(SDL_Renderer* renderer)
{
	if (m_texture)
		SDL_RenderCopy(renderer, m_texture, NULL, &m_rect);
}