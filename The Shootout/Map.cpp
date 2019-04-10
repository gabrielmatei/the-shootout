#include "pch.h"
#include "Map.h"

Map::Map() : _map(_height, vector<char>(_width))
{
}

Map::~Map()
{
}

void Map::Init()
{
	for (int i = 0; i < _height; i++)
		for (int j = 0; j < _width; j++)
			_map[i][j] = LAND_TILE;
}

void Map::Show()
{
	for (int i = 0; i < _height; i++)
	{
		for (int j = 0; j < _width; j++)
			cout << _map[i][j] << std::setw(2);
		cout << "\n";
	}
}
