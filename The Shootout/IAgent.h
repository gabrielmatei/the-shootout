#pragma once

#include <string>
#include <vector>
using namespace std;

class IAgent
{
protected:
	string _name;
	int _maxHealth;
	int _health;
	int _range;
	int _speed;
	int _damage;
	pair<int, int> _position;
public:
	string GetName();
	int GetHealth();
	pair<int, int> GetPosition();
	int GetRange();

	bool IsDead();

	virtual void TakeDamage(int) = 0;
	virtual void Attack(IAgent*) = 0;
	virtual void Move(int) = 0;
	virtual void Play(vector<IAgent*>) = 0;
};