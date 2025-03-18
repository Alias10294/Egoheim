#include <algorithm>

#include "ResourceManager.hpp"

ResourceManager::ResourceManager(SDL_Renderer* renderer)
    : m_renderer(renderer), m_textures()
{ }
ResourceManager::~ResourceManager()
{
    m_textures.clear();
}

std::shared_ptr<SDL_Texture> ResourceManager::GetTexture(const std::string& texturePath)
{
    if (m_textures.find(texturePath) == m_textures.end())
        LoadTexture(texturePath);
    
    return m_textures[texturePath];
}


void ResourceManager::LoadTexture(const std::string& texturePath)
{
    SDL_Texture* texture = IMG_LoadTexture(m_renderer, texturePath.c_str());
    
    m_textures[texturePath] = std::shared_ptr<SDL_Texture>(texture, SDL_DestroyTexture);
}

void ResourceManager::UnloadTexture(const std::string& texturePath)
{
    m_textures.erase(texturePath);
}