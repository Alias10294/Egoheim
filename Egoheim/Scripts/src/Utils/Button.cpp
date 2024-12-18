#include "../../includes/Utils/Button.h"
#include "../../includes/Game.h"
#include <iostream>

Button::Button(SDL_Texture* textures, AnimatedTextureInfo textureInfo, SDL_Rect rect, std::function<void()> onClick)
	: m_texture(textures, textureInfo), m_onClick(onClick)
{
	const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();
	m_rect = SDL_Rect
	{
		windowCoeffs.w * rect.x,
		windowCoeffs.h * rect.y,
		windowCoeffs.w * rect.w,
		windowCoeffs.h * rect.h
	};
}
Button::~Button()
{ }

void Button::HandleEvents(const SDL_Event& event)
{
	int x;
	int y;
	SDL_GetMouseState(&x, &y);
	bool mouseOnButton = (
		m_rect.x <= x && x < m_rect.x + m_rect.w &&
		m_rect.y <= y && y < m_rect.y + m_rect.h);
	if (mouseOnButton)
	{
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && m_onClick)
			m_onClick();
		m_isHovered = true;
	}
	else
		m_isHovered = false;
}
void Button::Update(const uint32_t deltaTimeMs)
{
	m_texture.UpdateReact(deltaTimeMs, m_isHovered);
}
void Button::Render(SDL_Renderer* renderer)
{
	m_texture.Render(renderer, &m_rect);
}