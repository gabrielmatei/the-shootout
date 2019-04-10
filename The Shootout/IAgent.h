#pragma once

class IAgent
{
protected:
	int _health;
	int _visibility;
public:
	int GetHealth();
	virtual int TakeDamage(int) = 0;
};