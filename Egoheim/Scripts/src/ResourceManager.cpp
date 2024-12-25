#include "../includes/ResourceManager.h"
#include "SDL2/SDL_image.h"
#include <format>

ResourceManager::ResourceManager()
	: m_renderer(nullptr)
{ }
ResourceManager::~ResourceManager()
{ }

void ResourceManager::Start(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
SDL_Texture* ResourceManager::LoadTexture(const char* path)
{
	return IMG_LoadTexture(
		m_renderer,
		path);
}