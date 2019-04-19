#include "pch.h"
#include "IAgent.h"

string IAgent::GetName()
{
	return _name;
}

int IAgent::GetTotalDamage()
{
	return _weapon->GetDamage();
}

int IAgent::GetTotalCriticalStrike()
{
	return _weapon->GetCriticalStrike();
}

int IAgent::GetTotalHealth()
{
	return _health + _armor->GetBonusHealth();
}

int IAgent::GetTotalArmor()
{
	return _armor->GetArmor();
}

int IAgent::GetTotalRange()
{
	return _range + _weapon->GetBonusRange() + _weapon->GetBonusRange();
}

int IAgent::GetTotalSpeed()
{
	return _speed + _armor->GetBonusSpeed();
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

AgentStats IAgent::GetStats()
{
	string name = GetName();
	int damage = GetTotalDamage();
	int critical = GetTotalCriticalStrike();
	int health = GetTotalHealth();
	int armor = GetTotalArmor();
	int range = GetTotalRange();
	int speed = GetTotalSpeed();

	return { name, damage, critical, health, armor, range, speed };
}

bool IAgent::IsDead()
{
	return _health <= 0;
}
