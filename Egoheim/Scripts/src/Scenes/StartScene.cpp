#include "../../includes/Scenes/StartScene.h"
#include "../../includes/Utils/TextButton.h"
#include <random>
#include <format>

StartScene::StartScene()
	: m_background(nullptr), m_buttonBackground(nullptr), m_startButtons()
{ }
StartScene::~StartScene()
{
	SDL_DestroyTexture(m_background);
	for (int i = 0; i < 4; i++)
		delete m_startButtons[i];
	SDL_DestroyTexture(m_buttonBackground);
}

void StartScene::Start(SDL_Renderer* renderer)
{ 
	// Choose a random menu style
	const char* backgroundStyles[] = { "Bilskin" };

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, (sizeof(backgroundStyles) / sizeof(backgroundStyles[0]) - 1));
	const char* backgroundStyle = backgroundStyles[distribution(rng)];

	// Add the background image
	m_background = IMG_LoadTexture(
		renderer, 
		std::format(
			"Assets/StartScene/{}/Background{}.png", 
			backgroundStyle, 
			backgroundStyle).c_str());
	if (!m_background)
	{
		std::cerr << "Error on background loading." << IMG_GetError() << std::endl;
	}

	// Add the buttons
	m_buttonBackground = IMG_LoadTexture(
		renderer,
		std::format(
			"Assets/StartScene/{}/ButtonBackground{}.png",
			backgroundStyle,
			backgroundStyle).c_str());
	if (!m_buttonBackground)
	{
		std::cerr << "Error on background loading." << IMG_GetError() << std::endl;
	}
	AnimatedTextureInfo startButtonTextureInfo = { STARTBUTTON_NBFRAMES, STARTBUTTON_FRAMETIMES };

	m_startButtons[0] = new TextButton(
		m_buttonBackground,
		startButtonTextureInfo, 
		"play", 
		{ STARTBUTTON_X, STARTBUTTON_Y_PLAY, STARTBUTTON_W, STARTBUTTON_H }); // "Play" button
	m_startButtons[1] = new TextButton(
		m_buttonBackground,
		startButtonTextureInfo, 
		"codex", 
		{ STARTBUTTON_X, STARTBUTTON_Y_CODEX, STARTBUTTON_W, STARTBUTTON_H }); // "Codex" button
	m_startButtons[2] = new TextButton(
		m_buttonBackground,
		startButtonTextureInfo, 
		"options",
		{ STARTBUTTON_X, STARTBUTTON_Y_OPTIONS, STARTBUTTON_W, STARTBUTTON_H }); // "Options" button
	m_startButtons[3] = new TextButton(
		m_buttonBackground,
		startButtonTextureInfo, 
		"quit",
		{ STARTBUTTON_X, STARTBUTTON_Y_QUIT, STARTBUTTON_W, STARTBUTTON_H },
		[this]() { this->End(); }); // "Quit" button

	// Start the scene
	m_isRunning = true;
}

void StartScene::HandleEvents(const SDL_Event& event)
{
	for (auto& button : m_startButtons)
		button->HandleEvents(event);
}
void StartScene::Update(const float deltaTime)
{
	for (auto& button : m_startButtons)
		button->Update(deltaTime);
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

void StartScene::End()
{
	m_isRunning = false;
}