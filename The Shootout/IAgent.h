#pragma once

#include <string>
#include <vector>
#include "Direction.h"
#include "AgentStats.h"
using namespace std;

class IAgent
{
protected:
	string _name;
	int _health;
	int _range;
	int _speed;
	int _damage;
	int _armor;
	pair<int, int> _position;
public:
	string GetName();
	int GetHealth();
	int GetArmor();
	pair<int, int> GetPosition();
	int GetRange();
	AgentStats GetStats();

	bool IsDead();

	virtual void TakeDamage(int) = 0;
	virtual void Attack(IAgent*) = 0;
	virtual void Move(int) = 0;
	virtual void Play(vector<IAgent*>) = 0;
};