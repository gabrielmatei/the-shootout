#include "pch.h"
#include "Sniper.h"

Sniper::Sniper(string name, IWeapon *weapon, IArmor *armor, pair<int, int> position)
{
	_name = name;
	_position = position;
	_health = MAX_HEALTH;
	_range = MAX_RANGE;
	_speed = 1;
	_weapon = weapon;
	_armor = armor;
}

Sniper::~Sniper()
{
}

void Sniper::TakeDamage(int amount)
{
	/*if (_armor >= amount)
	{
		_armor -= amount;
		return;
	}
	else if (_armor != 0)
	{
		amount -= _armor->GetArmor();
		_armor = 0;
	}*/

	_health -= amount;
	if (_health < 0)
		_health = 0;
}

void Sniper::Attack(IAgent *target)
{
	int damage = _weapon->Shoot();
	target->TakeDamage(damage);
}

void Sniper::Move(int direction)
{
	if (direction & Direction::Up)
	{
		if (Map::IsInside(pair<int, int>(_position.first - _speed, _position.second)))
			_position.first -= _speed;
	}
	if (direction & Direction::Down)
	{
		if (Map::IsInside(pair<int, int>(_position.first + _speed, _position.second)))
			_position.first += _speed;
	}
	if (direction & Direction::Left)
	{
		if (Map::IsInside(pair<int, int>(_position.first, _position.second - _speed)))
			_position.second -= _speed;
	}
	if (direction & Direction::Right)
	{
		if (Map::IsInside(pair<int, int>(_position.first, _position.second + _speed)))
			_position.second += _speed;
	}
}

void Sniper::Play(vector<IAgent*> targets)
{
	if (IsDead())
		return;

	IAgent* bestTarget = NULL;
	int bestDistance = 999999;
	for (auto target : targets)
	{
		int distance = Map::GetDistance(_position, target->GetPosition());
		if (distance < bestDistance || (distance == bestDistance && target->GetHealth() < bestTarget->GetHealth()))
		{
			bestTarget = target;
			bestDistance = distance;
		}
	}

	if (bestTarget != NULL)
	{
		if (bestDistance <= _range)
		{
			Attack(bestTarget);
		}
		else
		{
			int direction = Map::GetDirection(_position, bestTarget->GetPosition());
			Move(direction);
		}
	}
}