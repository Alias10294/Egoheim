#include "SDLContext.hpp"

SDLContext::SDLContext()
    : m_window(nullptr), m_renderer(nullptr)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_CreateWindowAndRenderer
    (
        SCREEN_WIDTH, 
        SCREEN_HEIGHT, 
        SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_SHOWN, 
        &m_window, 
        &m_renderer
    );

    SDL_RenderSetLogicalSize(m_renderer, SCREEN_WIDTH, SCREEN_HEIGHT);
}
SDLContext::~SDLContext()
{
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    SDL_Quit();
}

SDL_Window* SDLContext::GetWindow() const noexcept
{
    return m_window;
}
SDL_Renderer* SDLContext::GetRenderer() const noexcept
{
    return m_renderer;
}