#include "../../includes/Scenes/CombatScene.h"

CombatScene::CombatScene(ResourceManager& resourceManager, std::shared_ptr<Character> character1, std::shared_ptr<Character> character2)
	: Scene(resourceManager), m_character1(character1), m_character2(character2)
{ }
CombatScene::~CombatScene()
{ }

void CombatScene::Init(SDL_Renderer* renderer)
{ }
void CombatScene::Quit()
{
}

void CombatScene::HandleEvents(const SDL_Event& event)
{ }
void CombatScene::Update(const uint32_t deltaTimeMs)
{ }
void CombatScene::Render(SDL_Renderer* renderer)
{ }