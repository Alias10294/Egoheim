#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <functional>
#include "AnimatedTexture.h"

class Button
{
protected:
	SDL_Rect m_rect;
	AnimatedTexture m_texture;
	std::function<void()> m_onClick;
	bool m_isHovered = false;

public:
	Button(SDL_Texture* textures, AnimatedTextureInfo textureInfo, SDL_Rect rect, std::function<void()> onClick = nullptr);
	virtual ~Button();

	virtual void HandleEvents(const SDL_Event& event); 
	virtual void Update(const uint32_t deltaTimeMs);
	virtual void Render(SDL_Renderer* renderer);
};

#endif BUTTON_H
