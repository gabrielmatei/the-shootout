#include "pch.h"
#include "Map.h"

Map::Map() : _map(_height, vector<char>(_width))
{
}

Map::~Map()
{
}

void Map::Init(vector<IAgent*>* agents)
{
	_agents = agents;
	Clear();
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
			cout << _map[i][j] << std::setw(2);
		cout << "\n";
	}
}

void Map::AddAgent(IAgent* agent)
{
	auto position = agent->GetPosition();
	_map[position.first][position.second] = AGENT_TILE;

	AddRange(position, agent);
}

void Map::AddRange(pair<int, int> currentPosition, IAgent* agent)
{
	if (!IsInside(currentPosition))
		return;

	if (currentPosition != agent->GetPosition())
	{
		if (_map[currentPosition.first][currentPosition.second] != LAND_TILE)
			return;

		if (GetDistance(currentPosition, agent->GetPosition()) > agent->GetRange())
			return;

		if (_map[currentPosition.first][currentPosition.second] != AGENT_TILE)
			_map[currentPosition.first][currentPosition.second] = RANGE_TILE;
	}

	AddRange(pair<int, int>(currentPosition.first + 1, currentPosition.second), agent);
	AddRange(pair<int, int>(currentPosition.first - 1, currentPosition.second), agent);
	AddRange(pair<int, int>(currentPosition.first, currentPosition.second + 1), agent);
	AddRange(pair<int, int>(currentPosition.first, currentPosition.second - 1), agent);
}

void Map::Clear()
{
	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _width; j++)
			_map[i][j] = LAND_TILE;
}

int Map::GetDistance(pair<int, int> a, pair<int, int> b)
{
	return sqrt(pow((a.first - b.first), 2) + pow((a.second - b.second), 2));
}

bool Map::IsInside(pair<int, int> position)
{
	return position.first >= 0 && position.first < _height && position.second >= 0 && position.second < _width;
}
