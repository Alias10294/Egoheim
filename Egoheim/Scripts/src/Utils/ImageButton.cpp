#include "../../includes/Utils/ImageButton.h"
#include "../../includes/Game.h"

ImageButton::ImageButton(SDL_Texture* textures, AnimatedTextureInfo textureInfo, SDL_Texture* image, int x, int y, int w, int h)
	: Button(textures, textureInfo, x, y, w, h), m_image(image)
{
	SDL_QueryTexture(image, NULL, NULL, &m_imageRect.w, &m_imageRect.h);
	const WindowCoeffs windowCoeffs = Game::GetWindowCoeffs();

	m_imageRect.x = ((x + w / 2) - (m_imageRect.w / 2)) * windowCoeffs.w;
	m_imageRect.y = ((y + h / 2) - (m_imageRect.h / 2)) * windowCoeffs.h;
	m_imageRect.w *= windowCoeffs.w;
	m_imageRect.h *= windowCoeffs.h;
}
ImageButton::~ImageButton()
{
	SDL_DestroyTexture(m_image);
}

void ImageButton::Render(SDL_Renderer* renderer)
{
	m_texture.Render(renderer, &m_rect);
	if (m_image)
		SDL_RenderCopy(renderer, m_image, NULL, &m_imageRect);
}