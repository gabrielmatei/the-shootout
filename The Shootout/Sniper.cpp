#include "pch.h"
#include "Sniper.h"

Sniper::Sniper(string name, int damage, pair<int, int> position)
{
	_name = name;
	_position = position;
	_health = MAX_HEALTH;
	_range = MAX_RANGE;
	_speed = 1;
	_damage = damage;
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

void Sniper::Attack(IAgent *target)
{
	target->TakeDamage(_damage);
}

void Sniper::Move(Direction direction)
{
	switch (direction)
	{
	case Direction::Up:
		if (Map::IsInside(pair<int, int>(_position.first - _speed, _position.second)))
			_position.first -= _speed;
		break;
	case Direction::Down:
		if (Map::IsInside(pair<int, int>(_position.first + _speed, _position.second)))
			_position.first += _speed;
		break;
	case Direction::Left:
		if (Map::IsInside(pair<int, int>(_position.first, _position.second - _speed)))
			_position.second -= _speed;
		break;
	case Direction::Right:
		if (Map::IsInside(pair<int, int>(_position.first, _position.second + _speed)))
			_position.second += _speed;
		break;
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
		if (distance < bestDistance)
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
			Direction direction = Map::GetDirection(_position, bestTarget->GetPosition());
			Move(direction);
		}
	}
}