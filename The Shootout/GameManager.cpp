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
	_map.Init(&_agents);
}

void GameManager::Loop()
{
	while (true)
	{
		Update();
		RemoveDeadAgents();
		sleep_for(seconds(2));
	}
}

void GameManager::Update()
{
	_round++;

	_agents[0]->TakeDamage(10);

	Display();
}

void GameManager::Display()
{
	system("cls");

	cout << "Round " << _round << "\n\n";

	for (int i = 0; i < _agents.size(); i++)
	{
		cout << "Agent " << _agents[i]->GetName() << ": " << _agents[i]->GetHealth() << "\n";
	}

	_map.Show();

	cout << "\n\n";
}

void GameManager::AddAgent(IAgent* agent)
{
	_agents.push_back(agent);
}

void GameManager::RemoveDeadAgents()
{
	_agents.erase(
		remove_if(
			_agents.begin(),
			_agents.end(),
			[](IAgent* i) { return i->IsDead(); }),
		_agents.end()
	);
}
