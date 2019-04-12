#pragma once

#include "IAgent.h"
#include "MAp.h"

class Sniper : public IAgent
{
private:
	const int MAX_HEALTH = 100;
	const int MAX_RANGE = 4;
public:
	Sniper(string, int, pair<int, int>);
	~Sniper();

	void TakeDamage(int);
	void Attack(IAgent*);
	void Move(Direction);
	void Play(vector<IAgent*>);
};