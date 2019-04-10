#include "pch.h"
#include "GameManager.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Init()
{
	_round = 0;
	_map.Init();
}

void GameManager::Loop()
{
	while (true)
	{
		Update();
		sleep_for(seconds(2));
	}
}

void GameManager::Update()
{
	_round++;

	Display();
}

void GameManager::Display()
{
	cout << "Round "<< _round << "\n\n";
	
	_map.Show();

	cout << "\n\n";
}
