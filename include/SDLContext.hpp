#ifndef SDLCONTEXT_HPP
#define SDLCONTEXT_HPP

#include "SDL.h"

constexpr int SCREEN_WIDTH = 480;
constexpr int SCREEN_HEIGHT = 270;

class SDLContext
{
public:
    SDLContext();
    ~SDLContext();

    SDL_Window* GetWindow() const noexcept;
    SDL_Renderer* GetRenderer() const noexcept;

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
};

#endif