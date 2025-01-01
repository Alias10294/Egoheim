#ifndef COMBATSCENE_H
#define COMBATSCENE_H
#include <iostream>
#include "Scene.h"
#include "../CombatElements/CharacterElements/Character.h"

class CombatScene : public Scene
{
private:
	const std::shared_ptr<Character> m_character1;
	const std::shared_ptr<Character> m_character2;

public:
	CombatScene(ResourceManager& resourceManager, std::shared_ptr<Character> character1, std::shared_ptr<Character> character2);
	~CombatScene();

	virtual void Start(SDL_Renderer* renderer) override;

	virtual void HandleEvents(const SDL_Event& event) override;
	virtual void Update(const uint32_t deltaTimeMs) override;
	virtual void Render(SDL_Renderer* renderer) override;

	virtual void End() override;
};

#endif COMBATSCENE_H