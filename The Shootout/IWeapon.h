#pragma once
#include <string>
using namespace std;

class IWeapon
{
protected:
	int _damage;
	int _criticalStrike;
	int _bonusRange;
public:
	int GetDamage();
	int GetCriticalStrike();
	int GetBonusRange();
	virtual int Shoot() = 0;
};