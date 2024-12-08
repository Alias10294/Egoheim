#ifndef STARTSCENE_H 
#define STARTSCENE_H

#include <vector>
#include "Scene.h"
#include "../MenuElements/Button.h"

class StartScene : public Scene
{
private:
	SDL_Texture* m_background;
	std::vector<Button*> m_startButtons;
	
public:
	StartScene();
	~StartScene() override;

	void Start(SDL_Renderer* renderer) override;

	void HandleEvents(const SDL_Event& event) override;
	void Render(SDL_Renderer* renderer) override;

	void End() override;
};

#endif STARTSCENE_H