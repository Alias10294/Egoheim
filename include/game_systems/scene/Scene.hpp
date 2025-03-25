#ifndef SCENE_HPP
#define SCENE_HPP

class SceneManager;

class Scene 
{
public:
    Scene(SceneManager& manager);
    ~Scene();

    void Run();

private:
    SceneManager& m_manager;
};

#endif