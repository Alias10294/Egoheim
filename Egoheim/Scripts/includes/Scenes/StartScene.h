#ifndef STARTSCENE_H 
#define STARTSCENE_H

#include "Scene.h"
#include "../Utils/Button.h"

constexpr int STARTBUTTON_X = 6;
constexpr int STARTBUTTON_W = 92;
constexpr int STARTBUTTON_H = 21;
constexpr int STARTBUTTON_Y_PLAY = 70;
constexpr int STARTBUTTON_Y_CODEX = 101;
constexpr int STARTBUTTON_Y_OPTIONS = 132;
constexpr int STARTBUTTON_Y_QUIT = 163;

constexpr int STARTBUTTON_NBFRAMES = 3;
constexpr float STARTBUTTON_FRAMETIMES[] = { 0.1f, 0.1f, 0.1f };

class StartScene : public Scene
{
private:
	SDL_Texture* m_background;
	SDL_Texture* m_buttonBackground;
	Button* m_startButtons[4];
	
public:
	StartScene();
	~StartScene() override;

	virtual void Start(SDL_Renderer* renderer) override;

	virtual void HandleEvents(const SDL_Event& event) override;
	virtual void Update(const float deltaTime) override;
	virtual void Render(SDL_Renderer* renderer) override;

	virtual void End() override;
};

#endif STARTSCENE_H