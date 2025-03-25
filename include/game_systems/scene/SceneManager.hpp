#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include <stack>
#include <memory>

#include "Scene.hpp"

class SceneManager
{
public:
    SceneManager();
    ~SceneManager();
    
private:
    std::stack<std::unique_ptr<Scene>> m_scenes;
};

#endif