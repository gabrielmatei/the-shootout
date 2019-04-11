#pragma once

#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include "IAgent.h"
using namespace std;

class Map
{
private:
	const unsigned int _width = 25;
	const unsigned int _height = 25;

	vector<vector<char>> _map;

	const char LAND_TILE = '-';
	const char AGENT_TILE = '@';
	const char RANGE_TILE = '=';

	vector<IAgent*>* _agents;

	void Update();
public:
	Map();
	~Map();

	void Init(vector<IAgent*>*);

	void AddAgent(IAgent*);
	void AddRange(pair<int, int>, IAgent*);

	void Show();
	void Clear();

	int GetDistance(pair<int, int>, pair<int, int>);
	bool IsInside(pair<int, int>);
};