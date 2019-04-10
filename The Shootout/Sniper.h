#pragma once

#include "IAgent.h"

class Sniper : public IAgent
{
public:
	Sniper();
	~Sniper();

	void TakeDamage();
};