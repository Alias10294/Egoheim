#include "../includes/SceneManager.h"
#include "../includes/Scenes/StartScene.h"

SceneManager::SceneManager()
	: indexCurrentScene(0)
{ }
SceneManager::~SceneManager()
{
	for (int i = 0; i < 2; i++)
		delete scenes[i];
}

void SceneManager::Start(ResourceManager& resourceManager)
{
	scenes[0] = (Scene*)new StartScene(resourceManager);
}
void SceneManager::RunScene(SDL_Renderer* renderer)
{
	scenes[indexCurrentScene]->Start(renderer);
	while (scenes[indexCurrentScene]->IsRunning())
		scenes[indexCurrentScene]->Run(renderer);
	scenes[indexCurrentScene]->End();
}
void SceneManager::SetCurrentScene(int index)
{
	indexCurrentScene = index;
}