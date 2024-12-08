#include <iostream>
#include "../../../includes/CombatElements/CharacterElements/Stamina.h"

Stamina::Stamina(const std::int8_t maxStamina, const float regenDelay, const float regenRate)
	: m_maxStamina(maxStamina), m_currentStamina(maxStamina), m_regeneration(maxStamina, regenDelay, regenRate)
{ }