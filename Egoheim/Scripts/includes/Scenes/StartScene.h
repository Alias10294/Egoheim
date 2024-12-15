#ifndef STARTSCENE_H 
#define STARTSCENE_H

#include "Scene.h"
#include "../Utils/Button.h"

constexpr int STARTBUTTON_X = 8;
constexpr int STARTBUTTON_W = 88;
constexpr int STARTBUTTON_H = 17;
constexpr int STARTBUTTON_Y_PLAY = 72;
constexpr int STARTBUTTON_Y_CODEX = 103;
constexpr int STARTBUTTON_Y_OPTIONS = 134;
constexpr int STARTBUTTON_Y_QUIT = 165;

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