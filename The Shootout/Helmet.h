#pragma once

#include "IArmor.h"

class Helmet : public IArmor
{
private:
	const int MAX_ARMOR = 20;
	const int MAX_HEALTH = 20;
	const int MAX_SPEED = 1;
	const int MAX_RANGE = 2;
public:
	Helmet();
	~Helmet();
	int Defend(int);
};