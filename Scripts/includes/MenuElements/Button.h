#ifndef BUTTON_H
#define BUTTON_H

#include "SDL.h"

class Button
{
protected:
	SDL_Rect m_rect;
	SDL_Texture* m_texture;

public:
	Button(SDL_Texture* texture, int x, int y, int w, int h);
	~Button();

	virtual void Render(SDL_Renderer* renderer);
};

#endif BUTTON_H
