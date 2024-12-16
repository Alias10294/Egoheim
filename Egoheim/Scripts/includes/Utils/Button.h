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
	std::function<void()> m_action;

public:
	Button(SDL_Texture* textures, AnimatedTextureInfo textureInfo, int x, int y, int w, int h, std::function<void()> action = nullptr);
	virtual ~Button();

	void HandleEvents(const SDL_Event& event);
	void Update(const float deltaTime);
	virtual void Render(SDL_Renderer* renderer);
};

#endif BUTTON_H
