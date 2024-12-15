#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include "Button.h"
#include <SDL2/SDL.h>

class ImageButton : public Button
{
private:
	SDL_Texture* m_image;
	SDL_Rect m_imageRect;

public:
	ImageButton(SDL_Texture* texture, SDL_Texture* image, int x, int y, int w, int h);
	~ImageButton(); 

	virtual void Render(SDL_Renderer* renderer) override;
};

#endif IMAGEBUTTON_H