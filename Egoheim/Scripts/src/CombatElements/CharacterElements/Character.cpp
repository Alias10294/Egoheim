#include <iostream>
#include "../../../includes/CombatElements/CharacterElements/Character.h"

Character::Character()
	: m_health(24), m_stamina(12)
{
	std::cout << "Character initialized" << std::endl;
}