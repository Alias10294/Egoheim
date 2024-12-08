#include "../../includes/Scenes/StartScene.h"
#include "../../includes/Constants.h"
#include "../../includes/MenuElements/TextButton.h"
#include <random>

StartScene::StartScene()
	: m_background(nullptr)
{ }
StartScene::~StartScene()
{ }

void StartScene::Start(SDL_Renderer* renderer)
{ 
	// Choose a random menu style
	const char* backgrounds[] = { "Assets/StartScene/Bilskin/BackgroundBilskin.png" };
	const char* buttonBackgrounds[] = { "Assets/StartScene/Bilskin/ButtonBackgroundBilskin.png" };

	std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> distribution(0, (sizeof(backgrounds) / sizeof(backgrounds[0]) - 1));
	int iStyle = distribution(rng);

	// Add the background image
	m_background = IMG_LoadTexture(renderer, backgrounds[iStyle]);
	if (!m_background)
	{
		std::cerr << "Error on background loading." << IMG_GetError() << std::endl;
	}

	// Add the buttons
	SDL_Texture* buttonBackground = IMG_LoadTexture(renderer, buttonBackgrounds[iStyle]);
	if (!buttonBackground)
	{
		std::cerr << "Error on button background loading." << IMG_GetError() << std::endl;
	}
	m_startButtons.emplace_back(new TextButton(
		buttonBackground, 
		"play", 
		STARTBUTTON_X, 
		STARTBUTTON_Y_PLAY, 
		STARTBUTTON_W,
		STARTBUTTON_H)); // "Play" button
	m_startButtons.emplace_back(new TextButton(
		buttonBackground, 
		"codex", 
		STARTBUTTON_X,
		STARTBUTTON_Y_CODEX,
		STARTBUTTON_W,
		STARTBUTTON_H)); // "Codex" button
	m_startButtons.emplace_back(new TextButton(
		buttonBackground,
		"options",
		STARTBUTTON_X,
		STARTBUTTON_Y_OPTIONS,
		STARTBUTTON_W,
		STARTBUTTON_H)); // "Options" button
	m_startButtons.emplace_back(new TextButton(
		buttonBackground,
		"quit",
		STARTBUTTON_X,
		STARTBUTTON_Y_QUIT,
		STARTBUTTON_W,
		STARTBUTTON_H)); // "Quit" button

	// Start the scene
	m_isRunning = true;
}

void StartScene::HandleEvents(const SDL_Event& event)
{ }
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
	SDL_DestroyTexture(m_background);
	size_t size = m_startButtons.size();
	for (int i = 0; i < size; i++)
		delete m_startButtons[i];
	std::vector<Button*>().swap(m_startButtons);
}