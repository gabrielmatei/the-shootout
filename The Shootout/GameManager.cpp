#include "pch.h"
#include "GameManager.h"
#include <sstream>

bool GameManager::gameIsRunning = true;

GameManager::GameManager() {}

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

	Display();
}

void GameManager::Display()
{
	vector<string> logo{
		" ______ __              _______ __                __               __   ",
		"|       |  |--.-----.   |   _   |  |--.-----.-----|  |_.-----.--.--|  |_ ",
		"|.|   | |     |  -__|   |   1___|     |  _  |  _  |   _|  _  |  |  |   _|",
		"`-|.  |-|__|__|_____|   |____   |__|__|_____|_____|____|_____|_____|____|",
		"  |:  |                 |:  1   |                                        ",
		"  |::.|                 |::.. . |                                        ",
		"  `---'                 `-------'                                        ",
		"",
		"",
		"\tInstructions",
		"S. Start",
		"P. Pause",
		"D. Game details",
		"Q. Exit",
		""
	};

	system("cls");

	_map.Update();

	int width = _map.GetWidth();
	int height = _map.GetHeight();
	auto map = _map.GetMap();

	vector<string> right = logo;

	right.push_back("ROUND " + to_string(_round));
	right.push_back("");
	right.push_back("");
	for (auto a : _agents) {
		AgentStats stats = a->GetStats();

		right.push_back("  " + stats.Name);

		stringstream stream;
		stream << std::left << setw(8) << "Health" << std::right << setw(6) << stats.Health << std::left << setw(12) << "\t\tArmor" << std::right << setw(6) << stats.Armor;
		right.push_back(stream.str());
		stream.str("");

		stream << std::left << setw(8) << "Damage" << std::right << setw(6) << stats.Damage << std::left << setw(12) << "\t\tCritical" << std::right << setw(6) << stats.Critical;
		right.push_back(stream.str());
		stream.str("");

		stream << std::left << setw(8) << "Range" << std::right << setw(6) << stats.Range << std::left << setw(12) << "\t\tSpeed" << std::right << setw(6) << stats.Speed;
		right.push_back(stream.str());
		stream.str("");

		right.push_back("----------------------------------------");
	}

	for (int i = 0; i < height || i < right.size(); i++)
	{
		if (i < height)
			for (int j = 0; j < width; j++)
				cout << map[i][j];
		else
			for (int j = 0; j < width; j++)
				cout << " ";

		cout << "\t";

		if (i < right.size())
			cout << right[i];
		cout << "\n";
	}

	return;
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
	//cout << "\n";
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
