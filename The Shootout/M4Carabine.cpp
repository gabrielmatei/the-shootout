#include "pch.h"
#include "M4Carbine.h"

M4Carbine::M4Carbine()
{
	_damage = MAX_DAMAGE;
	_criticalStrike = MAX_CRITICAL;
	_bonusRange = MAX_RANGE;
}

M4Carbine::~M4Carbine()
{
}

int M4Carbine::Shoot()
{
	int crit = 0;
	if (rand() % 100 + 1 <= CHANCES_CRITICAL)
		crit = rand() % _criticalStrike + 1;

	return _damage + crit;
}
