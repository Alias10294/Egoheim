#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include "SDL.h"
#include "../event/EventDispatcher.hpp"
#include "DesktopState.hpp"
#include "ControllerState.hpp"
#include "InputConfig.hpp"
#include "DesktopInput.hpp"
#include "ControllerInput.hpp"

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

    InputConfig<DesktopInput> m_desktopInputConfig;
    std::array<InputConfig<ControllerInput>, NBMAX_CONTROLLERS> m_controllerInputConfigs;
};

#endif