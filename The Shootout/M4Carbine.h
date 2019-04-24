#pragma once

#include "IWeapon.h"

class M4Carbine : virtual public IWeapon
{
private:
	const int MAX_DAMAGE = 22;
	const int MAX_CRITICAL = 15;
	const int CHANCES_CRITICAL = 15;
	const int MAX_RANGE = 1;
public:
	M4Carbine();
	~M4Carbine();
	int Shoot();
};