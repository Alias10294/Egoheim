#include "../../includes/EventHandling/InputConfiguration.h"

InputConfiguration::InputConfiguration()
	: m_bindings
	{
		{ InputAction::MOVE_UP,    GameControllerControl() },
		{ InputAction::MOVE_DOWN,  GameControllerControl() },
		{ InputAction::MOVE_LEFT,  GameControllerControl() },
		{ InputAction::MOVE_RIGHT, GameControllerControl() },
		{ InputAction::DODGE,      GameControllerControl() },
		{ InputAction::ATTACK,     GameControllerControl() },
		{ InputAction::PARRY,      GameControllerControl() },
		{ InputAction::ABILITY_1,  GameControllerControl() },
		{ InputAction::ABILITY_2,  GameControllerControl() }
	}
{
	SetToDefault();
}
InputConfiguration::~InputConfiguration()
{ }

void InputConfiguration::SetToDefault()
{
	m_bindings[InputAction::MOVE_UP]    = SDL_CONTROLLER_AXIS_LEFTY;
	m_bindings[InputAction::MOVE_DOWN]  = SDL_CONTROLLER_AXIS_LEFTY;
	m_bindings[InputAction::MOVE_LEFT]  = SDL_CONTROLLER_AXIS_LEFTX;
	m_bindings[InputAction::MOVE_RIGHT] = SDL_CONTROLLER_AXIS_LEFTX;
	m_bindings[InputAction::DODGE]      = SDL_CONTROLLER_BUTTON_B;
	m_bindings[InputAction::ATTACK]     = SDL_CONTROLLER_AXIS_TRIGGERRIGHT;
	m_bindings[InputAction::PARRY]      = SDL_CONTROLLER_AXIS_TRIGGERLEFT;
	m_bindings[InputAction::ABILITY_1]  = SDL_CONTROLLER_BUTTON_LEFTSHOULDER;
	m_bindings[InputAction::ABILITY_2]  = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER;
}
void InputConfiguration::SetBinding(InputAction inputAction, GameControllerControl gameControllerControl)
{
	// Check existence of input action
	if (m_bindings.contains(inputAction) == false)
		return;

	// Swap controls if control is already bound
	for (int i = (int)InputAction::INPUT_ACTION_MIN; i < (int)InputAction::INPUT_ACTION_MAX; i++)
	{
		if (m_bindings.at((InputAction)i) == gameControllerControl)
		{
			m_bindings.at((InputAction)i) = m_bindings.at(inputAction);
			m_bindings.at(inputAction)    = gameControllerControl;
			return;
		}
	}

	// Set binding
	m_bindings[inputAction] = gameControllerControl;
}