#ifndef GAMECONTEXT_HPP
#define GAMECONTEXT_HPP

#include "event/EventDispatcher.hpp"
#include "input/InputManager.hpp"
#include "render/RenderingManager.hpp"
#include "resource/ResourceManager.hpp"
#include "scene/SceneManager.hpp"

struct GameContext
{
    EventDispatcher& eventDispatcher;
    InputManager& inputManager;
    RenderingManager& renderingManager;
    ResourceManager& resourceManager;
    SceneManager& sceneManager;
};

#endif