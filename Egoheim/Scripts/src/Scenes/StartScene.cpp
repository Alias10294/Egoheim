#include "../../includes/Scenes/StartScene.h"
#include "../../includes/Utils/TextButton.h"
#include <random>
#include <format>

StartScene::StartScene(ResourceManager& resourceManager, InputManager& inputManager)
	: Scene(resourceManager, inputManager), m_background(nullptr), m_buttonBackground(nullptr), m_startButtons()
{ }
StartScene::~StartScene()
{
	SDL_DestroyTexture(m_background);
	for (int i = 0; i < 4; i++)
		delete m_startButtons[i];
	SDL_DestroyTexture(m_buttonBackground);
}

void StartScene::Init(SDL_Renderer* renderer)
{ 
	// Choose a random menu style
	const char* backgroundStyles[] = { "Bilskin" };

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, (sizeof(backgroundStyles) / sizeof(backgroundStyles[0]) - 1));
	const char* backgroundStyle = backgroundStyles[distribution(rng)];

	// Add the background image
	m_background = m_resourceManager.LoadTexture(
		std::format(
			"Assets/StartScene/{}/Background{}.png",
			backgroundStyle,
			backgroundStyle).c_str());
	if (!m_background)
	{
		std::cerr << "Error on background loading." << IMG_GetError() << std::endl;
	}

	// Add the buttons
	m_buttonBackground = m_resourceManager.LoadTexture(
		std::format(
			"Assets/StartScene/{}/ButtonBackground{}.png",
			backgroundStyle,
			backgroundStyle).c_str());
	if (!m_buttonBackground)
	{
		std::cerr << "Error on background loading." << IMG_GetError() << std::endl;
	}
	AnimatedTextureInfo startButtonTextureInfo = { STARTBUTTON_NBFRAMES, STARTBUTTON_FRAMETIMES };
	for (int i = 0; i < 4; i++)
	{
		m_startButtons[i] = new TextButton(
			m_buttonBackground,
			startButtonTextureInfo,
			STARTBUTTON_TEXTS[i],
			{ STARTBUTTON_X, STARTBUTTON_Y + i * STARTBUTTON_SPACE,  STARTBUTTON_W, STARTBUTTON_H }, 
			[this]() { this->Quit(); });
	}

	// Start the scene
	m_isRunning = true;
}
void StartScene::Quit()
{
	m_isRunning = false;
}

void StartScene::HandleEvents(const SDL_Event& event)
{
	for (auto& button : m_startButtons)
		button->HandleEvents(event);
}
void StartScene::Update(const uint32_t deltaTimeMs)
{
	for (auto& button : m_startButtons)
		button->Update(deltaTimeMs);
}
void StartScene::Render(SDL_Renderer* renderer)
{
	SDL_RenderClear(renderer);

	if (m_background)
		SDL_RenderCopy(renderer, m_background, NULL, NULL);

	for (auto& button : m_startButtons)
		button->Render(renderer);

	SDL_RenderPresent(renderer); 
}