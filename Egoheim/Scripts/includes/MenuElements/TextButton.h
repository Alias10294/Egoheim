#ifndef TEXTBUTTON_H
#define TEXTBUTTON_H

#include "Button.h"
#include "SDL.h"

class TextButton : public Button
{
private:
	const char* m_text;
	SDL_Rect m_textRect;

public:
	TextButton(SDL_Texture* texture, const char* text, int x, int y, int w, int h);
	~TextButton();

	void Render(SDL_Renderer* renderer) override;
};

#endif TEXTBUTTON_H