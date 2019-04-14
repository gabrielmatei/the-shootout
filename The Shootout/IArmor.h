#pragma once

#include <string>
using namespace std;

class IArmor
{
protected:
	string _name;
	int _armor;
public:
	string GetName();
	int GetArmor();
};