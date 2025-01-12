#include "../../includes/GameManagers/ResourceManager.h"
#include "SDL2/SDL_image.h"
#include <format>

ResourceManager::ResourceManager()
	: m_renderer(nullptr)
{ }
ResourceManager::~ResourceManager()
{ }

void ResourceManager::Init(SDL_Renderer* renderer)
{
	m_renderer = renderer;
}
SDL_Texture* ResourceManager::LoadTexture(const char* file)
{
	return IMG_LoadTexture(
		m_renderer,
		file);
}