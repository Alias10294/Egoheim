#ifndef STARTSCENE_H 
#define STARTSCENE_H

#include "Scene.h"
#include "../Utils/Button.h"

constexpr int STARTBUTTON_X = 6;
constexpr int STARTBUTTON_Y = 70;
constexpr int STARTBUTTON_W = 92;
constexpr int STARTBUTTON_H = 21;
constexpr int STARTBUTTON_SPACE = 31;
constexpr const char* STARTBUTTON_TEXTS[] = { "play", "codex", "options", "quit" };

constexpr int STARTBUTTON_NBFRAMES = 3;
constexpr float STARTBUTTON_FRAMETIMES[] = { 30, 30, 30 };

class StartScene : public Scene
{
private:
	SDL_Texture* m_background;
	SDL_Texture* m_buttonBackground;
	Button* m_startButtons[4];
	
public:
	StartScene(ResourceManager& resourceManager);
	~StartScene() override;

	virtual void Init(SDL_Renderer* renderer) override;

	virtual void HandleEvents(const SDL_Event& event) override;
	virtual void Update(const uint32_t deltaTimeMs) override;
	virtual void Render(SDL_Renderer* renderer) override;

	virtual void End() override;
};

#endif STARTSCENE_H