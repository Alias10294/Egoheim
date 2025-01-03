#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Scenes/Scene.h"

class SceneManager
{
private:

	Scene* scenes[2];
	int indexCurrentScene;

public:
	SceneManager();
	~SceneManager();

	void Start(ResourceManager& resourceManager);
	void RunScene(SDL_Renderer* renderer);
	void SetCurrentScene(int index);
};

#endif SCENEMANAGER_H