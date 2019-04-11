#include "pch.h"
#include "Sniper.h"

Sniper::Sniper(string name, pair<int, int> position)
{
	_name = name;
	_position = position;
	_health = MAX_HEALTH;
	_range = MAX_RANGE;
}

Sniper::~Sniper()
{
}

void Sniper::TakeDamage(int amount)
{
	_health -= amount;
	if (_health < 0)
		_health = 0;
}

void Sniper::Heal(int amount)
{
	_health += amount;
	if (_health > _maxHealth)
		_health = _maxHealth;
}

int Sniper::Attack()
{
	return 0;
}