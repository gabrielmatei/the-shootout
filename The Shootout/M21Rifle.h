#pragma once

#include "IWeapon.h"

class M21Rifle : virtual public IWeapon
{	
private:
	const int MAX_DAMAGE = 40;
	const int MAX_CRITICAL = 25;
	const int CHANCES_CRITICAL = 30;
	const int MAX_RANGE = 2;
public:
	M21Rifle();
	~M21Rifle();
	int Shoot();
};