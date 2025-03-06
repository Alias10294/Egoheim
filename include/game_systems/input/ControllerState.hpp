#ifndef CONTROLLERSTATE_HPP
#define CONTROLLERSTATE_HPP

#include <array>

#include "SDL.h"

constexpr std::size_t NB_CONTROLLERBUTTONS = SDL_CONTROLLER_BUTTON_MAX;
constexpr std::size_t NB_CONTROLLERAXES = SDL_CONTROLLER_AXIS_MAX;

struct ControllerState
{
    SDL_GameController* controller = nullptr;
    SDL_JoystickID joystickID = -1;

    std::array<bool, NB_CONTROLLERBUTTONS> current{};
    std::array<bool, NB_CONTROLLERBUTTONS> previous{};

    std::array<short, NB_CONTROLLERAXES> axisValues{};
};

#endif