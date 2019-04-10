#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class Map
{
private:
	const unsigned int _width = 25;
	const unsigned int _height = 25;

	vector<vector<char>> _map;

	const char LAND_TILE = '-';
public:
	Map();
	~Map();

	void Init();
	void Show();
};