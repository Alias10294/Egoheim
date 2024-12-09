#include <iostream>
#include "../../../includes/CombatElements/CharacterElements/Health.h"

Health::Health(const std::int8_t maxHealth, const float regenDelay, const float regenRate)
	: m_maxHealth(maxHealth), m_currentHealth(maxHealth), m_regeneration(static_cast<std::int8_t>(7), regenDelay, regenRate) 
{ }