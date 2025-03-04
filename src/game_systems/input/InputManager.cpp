#include "InputManager.hpp"

InputManager::InputManager(EventDispatcher& dispatcher)
    : m_dispatcher(dispatcher),
      m_desktopState(), 
      m_controllerStates{ ControllerState(), ControllerState() }, 
      m_desktopInputConfig(), 
      m_controllerInputConfigs{ InputConfig<ControllerInput>(), InputConfig<ControllerInput>() }

{ }
InputManager::~InputManager()
{ }

void InputManager::ProcessInput()
{ 
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYUP:
        case SDL_KEYDOWN:
            break;
        
        case SDL_MOUSEBUTTONUP:
        case SDL_MOUSEBUTTONDOWN:
            break;
        case SDL_MOUSEWHEEL:
            break;
        case SDL_MOUSEMOTION:
            break;
        
        case SDL_CONTROLLERDEVICEADDED:
            break;
        case SDL_CONTROLLERDEVICEREMOVED:
            break;
        
        case SDL_CONTROLLERBUTTONUP:
        case SDL_CONTROLLERBUTTONDOWN:
            break;
        case SDL_CONTROLLERAXISMOTION:
            break;

        default:
            break;
        }
    }
}