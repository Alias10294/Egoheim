#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "SDL.h"
#include "../event/EventDispatcher.hpp"
#include "DesktopState.hpp"
#include "ControllerState.hpp"
#include "DesktopInputConfig.hpp"
#include "ControllerInputConfig.hpp"

constexpr std::size_t NBMAX_CONTROLLERS = 2;

class InputManager
{
public:
    InputManager(EventDispatcher& dispatcher);
    ~InputManager();

    void ProcessInput();

private:
    EventDispatcher& m_dispatcher;

    DesktopState m_desktopState;
    std::array<ControllerState, NBMAX_CONTROLLERS> m_controllerStates;

    DesktopInputConfig m_desktopConfig;
    std::array<ControllerInputConfig, NBMAX_CONTROLLERS> m_controllerConfigs;
};

#endif