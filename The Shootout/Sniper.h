#pragma once

#include "IAgent.h"

class Sniper : public IAgent
{
private:
	const int MAX_HEALTH = 100;
	const int MAX_RANGE = 4;
public:
	Sniper(string, pair<int, int>);
	~Sniper();

	void TakeDamage(int);
	void Heal(int);
	int Attack();
};