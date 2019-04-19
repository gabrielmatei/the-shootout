#pragma once

#include <string>
#include <vector>
#include "IWeapon.h"
#include "IArmor.h"
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
	IWeapon* _weapon;
	IArmor* _armor;
	pair<int, int> _position;
public:
	string GetName();
	int GetTotalDamage();
	int GetTotalCriticalStrike();
	int GetTotalHealth();
	int GetTotalArmor();
	int GetTotalRange();
	int GetTotalSpeed();
	IWeapon* GetWeapon();
	IArmor* GetArmor();
	pair<int, int> GetPosition();
	AgentStats GetStats();

	bool IsDead();

	virtual void TakeDamage(int) = 0;
	virtual void Attack(IAgent*) = 0;
	virtual void Move(int) = 0;
	virtual void Play(vector<IAgent*>) = 0;
};