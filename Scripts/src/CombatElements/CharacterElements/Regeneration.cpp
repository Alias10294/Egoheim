#include "../../../includes/CombatElements/CharacterElements/Regeneration.h"

Regeneration::Regeneration(const std::int8_t amount, const float delay, const float rate)
	: m_amount(amount), m_delay(delay), m_rate(rate)
{ }