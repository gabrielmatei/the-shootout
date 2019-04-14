#pragma once
#include <string>
using namespace std;

class IWeapon
{
protected:
	string _name;
	int _damage;
public:
	string GetName();
	int GetDamage();
};