#include "../../includes/GameManagers/SceneManager.h"
#include "../../includes/Scenes/StartScene.h"

SceneManager::SceneManager()
	: indexCurrentScene(0)
{ }
SceneManager::~SceneManager()
{
	Quit();
}

void SceneManager::Init(ResourceManager& resourceManager)
{
	scenes[0] = (Scene*)new StartScene(resourceManager);
}
void SceneManager::Quit()
{
	for (int i = 0; i < 2; i++)
		delete scenes[i];
}

void SceneManager::RunScene(SDL_Renderer* renderer)
{
	scenes[indexCurrentScene]->Init(renderer);
	while (scenes[indexCurrentScene]->IsRunning())
		scenes[indexCurrentScene]->Run(renderer);
	scenes[indexCurrentScene]->End();
}
void SceneManager::SetCurrentScene(int index)
{
	indexCurrentScene = index;
}