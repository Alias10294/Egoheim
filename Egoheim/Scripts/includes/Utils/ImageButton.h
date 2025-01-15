#ifndef IMAGEBUTTON_H
#define IMAGEBUTTON_H

#include "Button.h"
#include <SDL2/SDL.h>

class ImageButton : public Button
{
public:
	ImageButton(
		SDL_Texture* textures,
		const int nbFrames,
		const float* frameTimes,
		SDL_Texture* image,
		SDL_Rect rect,
		std::function<void()> onClick);
	~ImageButton();

	virtual void Render(SDL_Renderer* renderer) override;

private:
	SDL_Texture* m_image;
	SDL_Rect m_imageRect;
};

#endif IMAGEBUTTON_H