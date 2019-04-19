#pragma once

#include "IAgent.h"
#include "Map.h"

class Sniper : public IAgent
{
private:
	const int MAX_HEALTH = 100;
	const int MAX_RANGE = 4;
public:
	Sniper(string, IWeapon*, IArmor*, pair<int, int>);
	~Sniper();
	void TakeDamage(int);
	void Attack(IAgent*);
	void Move(int);
	void Play(vector<IAgent*>);
};