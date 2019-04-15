#include "pch.h"
#include "M21Rifle.h"

M21Rifle::M21Rifle()
{
	_damage = MAX_DAMAGE;
	_criticalStrike = MAX_CRITICAL;
	_bonusRange = MAX_RANGE;
}

M21Rifle::~M21Rifle()
{
}

int M21Rifle::Shoot()
{
	int crit = 0;
	if (rand() % 100 + 1 <= 30)
		crit = rand() % _criticalStrike + 1;

	return _damage + crit;
}
