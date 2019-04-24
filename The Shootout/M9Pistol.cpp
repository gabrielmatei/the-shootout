#include "pch.h"
#include "M9Pistol.h"

M9Pistol::M9Pistol()
{
	_damage = MAX_DAMAGE;
	_criticalStrike = MAX_CRITICAL;
	_bonusRange = MAX_RANGE;
}

M9Pistol::~M9Pistol()
{
}

int M9Pistol::Shoot()
{
	return _damage;
}
