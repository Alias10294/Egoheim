#ifndef STARTSCENE_H 
#define STARTSCENE_H

#include "Scene.h"
#include "../Utils/Button.h"

class StartScene : public Scene
{
private:
	SDL_Texture* m_background;
	Button* m_startButtons[4];
	
public:
	StartScene();
	~StartScene() override;

	void Start(SDL_Renderer* renderer) override;

	void HandleEvents(const SDL_Event& event) override;
	void Update(const float deltaTime) override;
	void Render(SDL_Renderer* renderer) override;

	void End() override;
};

#endif STARTSCENE_H