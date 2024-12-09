#ifndef HEALTH_H
#define HEALTH_H

#include <iostream>
#include "Regeneration.h"

class Health
{
private:
	const std::int8_t m_maxHealth;
	std::int8_t m_currentHealth;

	Regeneration m_regeneration;
	
public:
	Health(const std::int8_t maxHealth, const float regenDelay = 5.0F, const float regenRate = 0.7F);
};

#endif HEALTH_H