#pragma once

#include <string>
using namespace std;

class IArmor
{
protected:
	int _armor;
	int _bonusHealth;
	int _bonusSpeed;
	int _bonusRange;
public:
	int GetArmor();
	int GetBonusHealth();
	int GetBonusSpeed();
	int GetBonusRange();
	virtual int Defend() = 0;
};