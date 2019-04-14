#include "pch.h"
#include "IWeapon.h"

string IWeapon::GetName()
{
	return _name;
}

int IWeapon::GetDamage()
{
	return _damage;
}