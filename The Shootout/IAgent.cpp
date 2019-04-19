#include "pch.h"
#include "IAgent.h"

string IAgent::GetName()
{
	return _name;
}

int IAgent::GetHealth()
{
	return _health;
}

IWeapon* IAgent::GetWeapon()
{
	return _weapon;
}

IArmor* IAgent::GetArmor()
{
	return _armor;
}

pair<int, int> IAgent::GetPosition()
{
	return _position;
}

int IAgent::GetRange()
{
	return _range + _weapon->GetBonusRange() + _weapon->GetBonusRange();
}

int IAgent::GetSpeed()
{
	return _speed + _armor->GetBonusSpeed();
}

AgentStats IAgent::GetStats()
{
	return {
		_name,
		_damage,
		_speed,
		_range,
		_health,
		0
	};
}

bool IAgent::IsDead()
{
	return _health <= 0;
}
