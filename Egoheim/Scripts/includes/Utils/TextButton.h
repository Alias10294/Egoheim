#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include "Button.h"
#include <SDL2/SDL.h>

class TextButton : public Button
{
private:
	const char* m_text;
	SDL_Rect m_textRect;

public:
	TextButton(
		SDL_Texture* textures, 
		AnimatedTextureInfo textureInfo, 
		const char* text, 
		SDL_Rect rect, 
		std::function<void()> onClick = nullptr);
	~TextButton();

	virtual void Render(SDL_Renderer* renderer) override;
};

#endif TEXTBUTTON_H