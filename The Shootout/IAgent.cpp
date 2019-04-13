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

int IAgent::GetArmor()
{
	return _armor;
}

pair<int, int> IAgent::GetPosition()
{
	return _position;
}

int IAgent::GetRange()
{
	return _range;
}

bool IAgent::IsDead()
{
	return _health <= 0;
}
