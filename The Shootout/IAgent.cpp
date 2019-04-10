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

bool IAgent::IsDead()
{
	return _health <= 0;
}
