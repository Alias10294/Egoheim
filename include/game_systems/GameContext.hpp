#ifndef GAMECONTEXT_HPP
#define GAMECONTEXT_HPP

#include <memory>

#include "event/EventDispatcher.hpp"
#include "input/InputManager.hpp"
#include "resource/ResourceManager.hpp"

struct GameContext
{
    std::unique_ptr<EventDispatcher> eventDispatcher;
    std::unique_ptr<InputManager> inputManager;
    std::unique_ptr<ResourceManager> resourceManager;
};

#endif