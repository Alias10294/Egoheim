#ifndef SCENE_H
#define SCENE_H
#include "SDL_image.h"
#include "../Font.h"

class Scene
{
protected:
	bool m_isRunning = false;

public:
	virtual ~Scene() = default;

	virtual void Start(SDL_Renderer* renderer) = 0;

	virtual void HandleEvents(const SDL_Event& event) = 0;
	virtual void Render(SDL_Renderer* renderer) = 0;
	void Update(SDL_Renderer* renderer);

	virtual void End() = 0;

	bool IsRunning() const;
};

#endif SCENE_H