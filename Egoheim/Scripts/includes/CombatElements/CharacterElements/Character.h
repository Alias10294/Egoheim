#ifndef CHARACTER_H
#define CHARACTER_H

#include "Health.h"
#include "Stamina.h"

class Character
{
private:
	Health m_health;
	Stamina m_stamina;
	// Parry parry;

public:
	Character();
};

#endif CHARACTER_H