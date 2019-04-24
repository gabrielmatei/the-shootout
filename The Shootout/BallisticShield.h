#pragma once

#include "IArmor.h"

class BallisticShield : public IArmor
{
private:
	const int MAX_ARMOR = 170;
	const int MAX_HEALTH = 0;
	const int MAX_SPEED = 0;
	const int MAX_RANGE = 0;
public:
	BallisticShield();
	~BallisticShield();
	int Defend(int);
};