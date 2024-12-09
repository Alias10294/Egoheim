#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include "Scene.h"

class SceneManager
{
private:
	Scene* scenes[2];
	int indexCurrentScene;

public:
	SceneManager();
	~SceneManager();

	void RunScene(SDL_Renderer* renderer);
	void SetCurrentScene(int index);
};

#endif SCENEMANAGER_H