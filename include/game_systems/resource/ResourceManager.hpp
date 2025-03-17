#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <unordered_map>
#include <string>
#include <memory>

#include "SDL.h"
#include "SDL_image.h"

class ResourceManager
{
public:
    ResourceManager(SDL_Renderer* renderer);
    ~ResourceManager();

    std::shared_ptr<SDL_Texture> GetTexture(const std::string& texturePath);

    void LoadTexture(const std::string& texturePath);

    void UnloadTexture(const std::string& texturePath);
    
private:
    SDL_Renderer* m_renderer;

    std::unordered_map<std::string, std::shared_ptr<SDL_Texture>> m_textures;
};

#endif