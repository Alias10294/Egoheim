#ifndef DESKTOPSTATE_HPP
#define DESKTOPSTATE_HPP

#include <array>

#include "SDL.h"

constexpr std::size_t NB_SCANCODES = SDL_NUM_SCANCODES;
constexpr std::size_t NB_MOUSEBUTTONS = 5;

struct KeyboardState
{
    std::array<bool, NB_SCANCODES> current{};
    std::array<bool, NB_SCANCODES> previous{};
};

struct MouseState
{
    std::array<bool, NB_MOUSEBUTTONS> current{};
    std::array<bool, NB_MOUSEBUTTONS> previous{};

    Sint32 x = 0;
    Sint32 y = 0;

    Sint32 wheelDelta = 0;
};

struct DesktopState
{
    KeyboardState keyboard;
    MouseState mouse;
};

#endif