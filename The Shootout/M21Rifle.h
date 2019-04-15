#pragma once

#include "IWeapon.h"

class M21Rifle : virtual public IWeapon
{
private:
	const int MAX_DAMAGE = 40;
public:
	M21Rifle();
	~M21Rifle();

	int Shoot();
};