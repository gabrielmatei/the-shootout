#include "pch.h"
#include "IArmor.h"

int IArmor::GetArmor()
{
	return _armor;
}

int IArmor::GetBonusHealth()
{
	return _bonusHealth;
}

int IArmor::GetBonusSpeed()
{
	return _bonusSpeed;
}

int IArmor::GetBonusRange()
{
	return _bonusRange;
}
