#ifndef BUTTON_H
#define BUTTON_H

#include <SDL2/SDL.h>
#include <functional>

class Button
{
protected:
	SDL_Rect m_rect;
	SDL_Texture* m_texture;
	std::function<void()> m_action;

public:
	Button(SDL_Texture* texture, int x, int y, int w, int h, std::function<void()> action = nullptr);
	virtual ~Button();

	virtual void HandleEvents(const SDL_Event& event);
	virtual void Render(SDL_Renderer* renderer);
};

#endif BUTTON_H
