#include "pch.h"
#include "BulletproofVest.h"

BulletproofVest::BulletproofVest()
{
	_armor = MAX_ARMOR;
	_bonusHealth = MAX_HEALTH;
	_bonusSpeed = MAX_SPEED;
	_bonusRange = MAX_RANGE;
}

BulletproofVest::~BulletproofVest()
{
}

int BulletproofVest::Defend(int damage)
{
	if (_armor > damage)
	{
		_armor -= damage;
		return 0;
	}
	else
	{
		damage -= _armor;
		_armor = 0;
	}
	if (damage == 0)
		return 0;

	if (_bonusHealth > damage)
	{
		_bonusHealth -= damage;
		return 0;
	}
	else
	{
		damage -= _bonusHealth;
		_bonusHealth = 0;
	}

	if (_armor == 0 && _bonusHealth == 0)
		_bonusSpeed = _bonusRange = 0;

	return damage;
}
