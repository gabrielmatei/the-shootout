#pragma once

#include "IWeapon.h"

class M9Pistol : virtual public IWeapon
{
private:
	const int MAX_DAMAGE = 8;
	const int MAX_CRITICAL = 0;
	const int CHANCES_CRITICAL = 0;
	const int MAX_RANGE = 0;
public:
	M9Pistol();
	~M9Pistol();
	int Shoot();
};