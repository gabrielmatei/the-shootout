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

int BulletproofVest::Defend()
{
	return 0;
}
