#include "pch.h"
#include "Map.h"

Map::Map() : _map(_height, vector<char>(_width)) {}

Map::~Map() {}

void Map::Init(vector<IAgent*>* agents)
{
	_agents = agents;
	Clear();
}

int Map::GetWidth()
{
	return _width;
}

int Map::GetHeight()
{
	return _height;
}

vector<vector<char>> Map::GetMap()
{
	return _map;
}

void Map::Update()
{
	Clear();
	for (auto agent : *_agents)
		AddAgent(agent);
}

void Map::Show()
{
	Update();

	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
			cout << _map[i][j];
		cout << "\n";
	}
}

void Map::AddAgent(IAgent* agent)
{
	auto position = agent->GetPosition();
	if (agent->IsDead())
	{
		_map[position.first][position.second] = AGENT_DEAD_TILE;
	}
	else
	{
		_map[position.first][position.second] = AGENT_TILE;
		AddRange(position, agent);
	}
}

void Map::AddRange(pair<int, int> currentPosition, IAgent* agent)
{
	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _width; j++)
		{
			if (GetDistance({ i, j }, agent->GetPosition()) > agent->GetTotalRange())
				continue;
			if (_map[i][j] != LAND_TILE)
				continue;
			_map[i][j] = RANGE_TILE;
		}
}

void Map::Clear()
{
	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _width; j++)
			_map[i][j] = LAND_TILE;
}

int Map::GetDistance(pair<int, int> a, pair<int, int> b)
{
	return (int)sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

int Map::GetDirection(pair<int, int> a, pair<int, int> b)
{
	int direction = 0;

	if (a.first > b.first)
		direction |= Direction::Up;
	if (a.first < b.first)
		direction |= Direction::Down;
	if (a.second > b.second)
		direction |= Direction::Left;
	if (a.second < b.second)
		direction |= Direction::Right;

	return direction;
}

bool Map::IsInside(pair<int, int> position)
{
	return position.first >= 0 && position.first < _height && position.second >= 0 && position.second < _width;
}
