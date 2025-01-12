#ifndef SCENE_H
#define SCENE_H
#include <SDL2/SDL_image.h>
#include "../Utils/Font.h"
#include "../GameManagers/ResourceManager.h"

constexpr int FPS_LIMIT = 60;

class Scene
{
private:
	const uint32_t m_frameDelayMs = 1000 / FPS_LIMIT;
	uint32_t m_accumulatedMs = 0;

protected:
	ResourceManager& m_resourceManager;

	bool m_isRunning = false;

public:
	Scene(ResourceManager& resourceManager);
	virtual ~Scene() = default;

	virtual void Init(SDL_Renderer* renderer) = 0;

	virtual void HandleEvents(const SDL_Event& event) = 0;
	virtual void Update(const uint32_t deltaTimeMs) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	void Run(SDL_Renderer* renderer);

	virtual void End() = 0;

	bool IsRunning() const;
};

#endif SCENE_H