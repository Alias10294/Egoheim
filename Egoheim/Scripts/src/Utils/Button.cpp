#include "../../includes/Utils/Button.h"
#include "../../includes/Game.h"
#include <iostream>

Button::Button(SDL_Texture* textures, AnimatedTextureInfo textureInfo, int x, int y, int w, int h, std::function<void()> action)
	: m_texture(textures, textureInfo), m_action(action)
{
	const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();
	m_rect = SDL_Rect
	{
		windowCoeffs.w * x,
		windowCoeffs.h * y,
		windowCoeffs.w * w,
		windowCoeffs.h * h
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
		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && m_action)
			m_action();
		if (!m_isHovered)
		{
			m_texture.StartAnimation();
		}
		m_isHovered = true;
	}
	else
	{
		if (m_isHovered)
		{
			m_texture.StartAnimation();
		}
		m_isHovered = false;
	}
}
void Button::Update(const float deltaTime)
{
	m_texture.Update(deltaTime);
}
void Button::Render(SDL_Renderer* renderer)
{
	m_texture.Render(renderer, &m_rect);
}