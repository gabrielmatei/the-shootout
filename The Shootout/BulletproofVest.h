#pragma once

#include "IArmor.h"

class BulletproofVest : public IArmor
{
private:
	const int MAX_ARMOR = 40;
public:
	BulletproofVest(string, int);
	~BulletproofVest();
};