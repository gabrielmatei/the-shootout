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
		sleep_for(milliseconds(300));
	}
}

void GameManager::Update()
{
	_round++;

	for (int i = 0; i < _agents.size(); i++)
	{
		vector<IAgent*> targets;
		for (int j = 0; j < i; j++)
			targets.push_back(_agents[j]);
		for (int j = i + 1; j < _agents.size(); j++)
			targets.push_back(_agents[j]);

		_agents[i]->Play(targets);
	}

	RemoveDeadAgents();
	Display();
}

void GameManager::Display()
{
	system("cls");

	cout << "Round " << _round << "\n\n";

	for (auto agent : _agents)
	{
		ShowAgentStats(agent->GetStats());
	}

	_map.Show();

	cout << "\n\n";
}

void GameManager::ShowAgentStats(AgentStats stats)
{
	cout << left;
	cout << "NAME: " << setw(8) << stats.Name << " - ";
	cout << "H: " << setw(4) << stats.Health << " ";
	cout << "A: " << setw(4) << stats.Armor << " ";
	cout << "D: " << setw(3) << stats.Damage << " ";
	cout << "S: " << setw(2) << stats.Speed << " ";
	cout << "R: " << setw(2) << stats.Range << " ";
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
