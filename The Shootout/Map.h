#pragma once

#include <iostream>
#include <vector>
#include <math.h>
#include "Direction.h"
#include "IAgent.h"
using namespace std;

class Map
{
private:
	static const unsigned int _width = 100;
	static const unsigned int _height = 40;

	vector<vector<char>> _map;

	const char LAND_TILE = (char)176;
	const char AGENT_TILE = (char)178;
	const char RANGE_TILE = (char)177;

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

	static int GetDistance(pair<int, int>, pair<int, int>);
	static int GetDirection(pair<int, int>, pair<int, int>);
	static bool IsInside(pair<int, int>);
};