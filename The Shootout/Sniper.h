#pragma once

#include "IAgent.h"

class Sniper : public IAgent
{
public:
	Sniper(string, int);
	~Sniper();

	void TakeDamage(int);
	void Heal(int);
	int Attack();
};