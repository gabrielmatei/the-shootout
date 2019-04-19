#pragma once

#include "IArmor.h"

class BulletproofVest : public IArmor
{
private:
	const int MAX_ARMOR = 44;
	const int MAX_HEALTH = 32;
	const int MAX_SPEED = 1;
	const int MAX_RANGE = 2;
public:
	BulletproofVest();
	~BulletproofVest();
	int Defend(int);
};