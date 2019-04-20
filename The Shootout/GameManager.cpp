#include "pch.h"
#include "GameManager.h"

bool GameManager::gameIsRunning = true;

GameManager::GameManager(){}

GameManager::~GameManager() {}

void GameManager::Init()
{
	_round = 0;
	_map.Init(&_agents);
}

void GameManager::ReadInputTask(std::atomic<bool>& programIsRunning)
{
	while (programIsRunning)
	{
		char input;
		cin >> input;

		switch (tolower(input))
		{
		case 'q':
			break;
		case 's':
			gameIsRunning = true;
			break;
		case 'p':
			gameIsRunning = false;
			break;
		}

		cin.clear();
		this_thread::sleep_for(milliseconds(500));
	}
}

void GameManager::Loop()
{
	atomic<bool> programIsRunning{ true };
	thread readInputTask(ReadInputTask, ref(programIsRunning));

	while (true)
	{
		if (gameIsRunning)
			Update();
		sleep_for(milliseconds(1000));
	}

	programIsRunning = false;
	readInputTask.join();
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

	cout << "Round " << _round << "\n";

	_map.Show();

	for (auto agent : _agents)
		ShowAgentStats(agent->GetStats());
}

void GameManager::ShowAgentStats(AgentStats stats)
{
	cout << left;
	cout << "NAME: " << setw(8) << stats.Name << " ";
	cout << "DAMAGE: " << setw(4) << stats.Damage << " ";
	cout << "CRIT: " << setw(4) << stats.Critical << " ";
	cout << "HEALTH: " << setw(3) << stats.Health << " ";
	cout << "ARMOR: " << setw(2) << stats.Armor << " ";
	cout << "RANGE: " << setw(2) << stats.Range << " ";
	cout << "SPEED: " << setw(2) << stats.Speed << " ";
	cout << "\n";
}

void GameManager::AddAgent(IAgent* agent)
{
	_agents.push_back(agent);
}

void GameManager::AddAgents(vector<IAgent*> agents)
{
	for (auto agent : agents)
		AddAgent(agent);
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
