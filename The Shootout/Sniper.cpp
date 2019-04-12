#include "pch.h"
#include "Sniper.h"

Sniper::Sniper(string name, int damage, pair<int, int> position)
{
	_name = name;
	_position = position;
	_health = MAX_HEALTH;
	_range = MAX_RANGE;
	_speed = 4;
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

void Sniper::Move(int direction)
{
	switch (direction)
	{
	case 1:
		if (Map::IsInside(pair<int, int>(_position.first - _speed, _position.second)))
			_position.first -= _speed; // up
		break;
	case 2:
		if (Map::IsInside(pair<int, int>(_position.first + _speed, _position.second)))
			_position.first += _speed; // down
		break;
	case 3:
		if (Map::IsInside(pair<int, int>(_position.first, _position.second - _speed)))
			_position.second -= _speed; // left
		break;
	case 4:
		if (Map::IsInside(pair<int, int>(_position.first, _position.second + _speed)))
			_position.second += _speed; // right
		break;
	}
}

void Sniper::Play(vector<IAgent*> targets)
{
	if (IsDead())
		return;

	for (auto target : targets)
	{
		int distance = Map::GetDistance(_position, target->GetPosition());
		if (distance <= _range)
			Attack(target);
		else
			Move(rand() % 4 + 1);
	}

}