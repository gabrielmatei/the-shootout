#include "pch.h"
#include "Sniper.h"
#include "GameManager.h"

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
	amount = _armor->Defend(amount);

	_health -= amount;
	if (_health <= 0)
	{
		_health = 0;
		GameManager::AddLog(GetName() + " is dead");
	}
}

void Sniper::Attack(IAgent *target)
{
	int damage = _weapon->Shoot();
	target->TakeDamage(damage);
}

void Sniper::Move(int direction)
{
	int speed = GetTotalSpeed();
	if (direction & Direction::Up)
	{
		if (Map::IsInside(pair<int, int>(_position.first - speed, _position.second)))
			_position.first -= speed;
	}
	if (direction & Direction::Down)
	{
		if (Map::IsInside(pair<int, int>(_position.first + speed, _position.second)))
			_position.first += speed;
	}
	if (direction & Direction::Left)
	{
		if (Map::IsInside(pair<int, int>(_position.first, _position.second - speed)))
			_position.second -= speed;
	}
	if (direction & Direction::Right)
	{
		if (Map::IsInside(pair<int, int>(_position.first, _position.second + speed)))
			_position.second += speed;
	}
}

void Sniper::Play(vector<IAgent*> targets)
{
	if (IsDead())
		return;

	IAgent* bestTarget = NULL;
	int bestDistance = numeric_limits<int>::max();
	for (auto target : targets)
	{
		if (target->IsDead())
			continue;

		int distance = Map::GetDistance(_position, target->GetPosition());
		if (distance < bestDistance || (distance == bestDistance && target->GetTotalHealth() < bestTarget->GetTotalHealth()))
		{
			bestTarget = target;
			bestDistance = distance;
		}
	}

	if (bestTarget != NULL)
	{
		if (bestDistance <= _range)
		{
			GameManager::AddLog(GetName() + " attacked " + bestTarget->GetName());
			
			Attack(bestTarget);
		}
		else
		{
			GameManager::AddLog(GetName() + " headed for " + bestTarget->GetName());
			
			int direction = Map::GetDirection(_position, bestTarget->GetPosition());
			Move(direction);
		}
	}
}