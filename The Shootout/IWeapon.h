#pragma once
#include <string>
using namespace std;

class IWeapon
{
protected:
	int _damage;
	int _criticalStrike;
public:
	int GetDamage();
	int GetCriticalStrike();

	virtual int Shoot() = 0;
};