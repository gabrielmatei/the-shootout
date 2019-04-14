#pragma once

#include "IWeapon.h"

class M21Rifle : public IWeapon
{
private:
	const int MAX_DAMAGE = 40;
public:
	M21Rifle(string, int);
	~M21Rifle();
};