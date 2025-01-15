#ifndef INPUTCONFIGURATION_H
#define INPUTCONFIGURATION_H

#include <vector>
#include <SDL2/SDL.h>
#include <unordered_map>
#include "Input.h"

class InputConfiguration
{
public:
	InputConfiguration();
	~InputConfiguration();

private:
	struct Action
	{
		const char* actionName;
		struct PossibleBindings
		{
			std::vector<SDL_EventType> controller;
			std::vector<SDL_EventType> computer;
		} 
		possibleBindings;
	};

	std::unordered_map<Action, Input> configuration;
};

#endif INPUTCONFIGURATION_H