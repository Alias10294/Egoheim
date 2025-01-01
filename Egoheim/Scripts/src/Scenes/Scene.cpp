#include "../../includes/Scenes/Scene.h"

Scene::Scene(ResourceManager& resourceManager)
	: m_resourceManager(resourceManager)
{ }

void Scene::Run(SDL_Renderer* renderer)
{
	const uint32_t frameStartMs = SDL_GetTicks();

	// Event handling
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
			m_isRunning = false;
		HandleEvents(event);
	}

	// Updating and rendering
	while (m_accumulatedMs >= m_frameDelayMs)
	{
		Update(m_frameDelayMs);
		Render(renderer);
		m_accumulatedMs -= m_frameDelayMs;
	}

	const uint32_t frameEndMs = SDL_GetTicks();
	m_accumulatedMs += frameEndMs - frameStartMs;
}

bool Scene::IsRunning() const
{
	return m_isRunning;
}