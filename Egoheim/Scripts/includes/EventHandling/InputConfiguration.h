#ifndef INPUTCONFIGURATION_H
#define INPUTCONFIGURATION_H

#include <SDL2/SDL.h>
#include <variant>
#include <unordered_map>
#include "InputAction.h"

typedef std::variant<SDL_GameControllerAxis, SDL_GameControllerButton> GameControllerControl;

class InputConfiguration
{
public:
	InputConfiguration();
	~InputConfiguration();

	void SetToDefault();
	void SetBinding(InputAction inputAction, GameControllerControl gameControllerControl);

private:
	std::unordered_map<InputAction, GameControllerControl> m_bindings;
};

#endif INPUTCONFIGURATION_H