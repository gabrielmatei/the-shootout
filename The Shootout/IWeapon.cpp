#include "pch.h"
#include "IWeapon.h"

int IWeapon::GetDamage()
{
	return _damage;
}

int IWeapon::GetCriticalStrike()
{
	return _criticalStrike;
}
