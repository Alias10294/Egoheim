#include "../../includes/Scenes/Scene.h"

void Scene::Run(SDL_Renderer* renderer)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			m_isRunning = false;
		HandleEvents(event);
		Update();
	}
	Render(renderer);
}

bool Scene::IsRunning() const
{
	return m_isRunning;
}