#ifndef SCENE_H
#define SCENE_H
#include <SDL2/SDL_image.h>
#include "../Utils/Font.h"

constexpr int FPS_LIMIT = 60;

class Scene
{
private:
	const float m_frameDelayMs = 1000.0f / FPS_LIMIT;
	uint32_t m_accumulatedMs = 0;

protected:
	bool m_isRunning = false;

public:
	virtual ~Scene() = default;

	virtual void Start(SDL_Renderer* renderer) = 0;

	virtual void HandleEvents(const SDL_Event& event) = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	void Run(SDL_Renderer* renderer);

	virtual void End() = 0;

	bool IsRunning() const;
};

#endif SCENE_H