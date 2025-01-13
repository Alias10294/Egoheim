#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "../Scenes/Scene.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Init(ResourceManager& resourceManager);
	void Quit();

	void RunScene(SDL_Renderer* renderer);
	void SetCurrentScene(int index);

private:
	Scene* scenes[2];
	int indexCurrentScene;
};

#endif SCENEMANAGER_H