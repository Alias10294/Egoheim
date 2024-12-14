#include "../../includes/Scenes/CombatScene.h"

CombatScene::CombatScene(std::shared_ptr<Character> character1, std::shared_ptr<Character> character2)
	: m_character1(character1), m_character2(character2)
{ }
CombatScene::~CombatScene()
{ }

void CombatScene::Start(SDL_Renderer* renderer)
{ }

void CombatScene::HandleEvents(const SDL_Event& event)
{ }
void CombatScene::Update(const float deltaTime)
{ }
void CombatScene::Render(SDL_Renderer* renderer)
{ }

void CombatScene::End()
{ }