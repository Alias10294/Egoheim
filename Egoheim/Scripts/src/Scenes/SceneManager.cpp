#include "../../includes/Scenes/SceneManager.h"
#include "../../includes/Scenes/StartScene.h"
#include "../../includes/Scenes/CombatScene.h"

SceneManager::SceneManager()
	: indexCurrentScene(0)
{
	scenes[0] = (Scene*)new StartScene();
}
SceneManager::~SceneManager()
{
	for (int i = 0; i < 2; i++)
		delete scenes[i];
}

void SceneManager::RunScene(SDL_Renderer* renderer)
{
	scenes[indexCurrentScene]->Start(renderer);
	while (scenes[indexCurrentScene]->IsRunning())
		scenes[indexCurrentScene]->Update(renderer);
	scenes[indexCurrentScene]->End();
}
void SceneManager::SetCurrentScene(int index)
{
	indexCurrentScene = index;
}