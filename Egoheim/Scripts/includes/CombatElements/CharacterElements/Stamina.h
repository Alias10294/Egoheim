#ifndef STAMINA_H
#define STAMINA_H

#include <iostream>
#include "Regeneration.h"

class Stamina
{
private:
	const std::int8_t m_maxStamina;
	std::int8_t m_currentStamina;

	Regeneration m_regeneration;

public:
	Stamina(const std::int8_t maxStamina, const float regenDelay = 2.0F, const float regenRate = 0.2F);
};

#endif STAMINA_H