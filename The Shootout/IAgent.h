#pragma once

#include <string>
using namespace std;

class IAgent
{
protected:
	string _name;
	int _maxHealth;
	int _health;
	int _visibility;
public:
	string GetName();
	int GetHealth();

	bool IsDead();

	virtual void TakeDamage(int) = 0;
	virtual void Heal(int) = 0;
	virtual int Attack() = 0;
};