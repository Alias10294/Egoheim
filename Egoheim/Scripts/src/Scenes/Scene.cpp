#include "../../includes/Scenes/Scene.h"

void Scene::Update(SDL_Renderer* renderer)
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			m_isRunning = false;
		HandleEvents(event);
	}
	Render(renderer);
}

bool Scene::IsRunning() const
{
	return m_isRunning;
}