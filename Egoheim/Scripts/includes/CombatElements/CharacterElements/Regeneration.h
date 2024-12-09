#ifndef REGENERATION_H
#define REGENERATION_H
#include <iostream>

struct Regeneration
{
private:
	const std::int8_t m_amount;
	const float m_delay;
	const float m_rate;

public:
	Regeneration(const std::int8_t amount, const float delay, const float rate);
};

#endif REGENERATION_H