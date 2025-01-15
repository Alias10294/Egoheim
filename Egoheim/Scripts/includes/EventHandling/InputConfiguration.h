#ifndef INPUTCONFIGURATION_H
#define INPUTCONFIGURATION_H

#include <SDL2/SDL.h>
#include <unordered_map>
#include "Input.h"

constexpr const int NB_ACTIONS = 1;
constexpr const int MAX_POSSIBLE_BINDINGS = 2;

class InputConfiguration
{
public:
	InputConfiguration();
	~InputConfiguration();

private:
	std::unordered_map<const char*, Input> configuration;
	const struct Action
	{
		const char* actionName;
		const struct PossibleBindings
		{
			SDL_EventType controller[MAX_POSSIBLE_BINDINGS];
			SDL_EventType desktop[MAX_POSSIBLE_BINDINGS];
		} 
		possibleBindings;
	} 
	actions[NB_ACTIONS];

};

#endif INPUTCONFIGURATION_H