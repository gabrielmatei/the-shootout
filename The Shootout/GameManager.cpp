#include "pch.h"
#include "GameManager.h"

bool GameManager::_gameInProgress = true;
bool GameManager::_gameIsRunning = true;
bool GameManager::_canShowLogs = false;
vector<string> GameManager::_logs;

GameManager::GameManager() {}

GameManager::~GameManager()
{
	for (auto agent : _agents)
		delete agent;
}

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
			_gameIsRunning = true;
			break;
		case 'p':
			_gameIsRunning = false;
			break;
		case 'd':
			_canShowLogs = true;
			_gameIsRunning = false;
			break;
		}

		cin.clear();
		this_thread::sleep_for(milliseconds(500));
	}
}

void GameManager::Start()
{
	cout << "\t\t ______ __              _______ __                __               __   \n";
	cout << "\t\t|       |  |--.-----.   |   _   |  |--.-----.-----|  |_.-----.--.--|  |_ \n";
	cout << "\t\t|.|   | |     |  -__|   |   1___|     |  _  |  _  |   _|  _  |  |  |   _|\n";
	cout << "\t\t`-|.  |-|__|__|_____|   |____   |__|__|_____|_____|____|_____|_____|____|\n";
	cout << "\t\t  |:  |                 |:  1   |                                        \n";
	cout << "\t\t  |::.|                 |::.. . |                                        \n";
	cout << "\t\t  `---'                 `-------'                                        \n\n\n";

	int numberOfAgents;
	cout << "Number of snipers: "; cin >> numberOfAgents;

	for (int i = 0; i < numberOfAgents; i++)
	{
		system("cls");

		string name;
		cout << "Enter name: ";
		cin >> name;

		int weapon, armor;
		cout << "Choose weapon: 1.M21Rifle   2.M4Carbine   3.M9Pistol: ";
		cin >> weapon;
		cout << "Choose armor: 1.BallisticShield   2.Helmet   3.BulletproofVest: ";
		cin >> armor;

		IWeapon* weaponPointer = NULL;
		IArmor* armorPointer = NULL;

		switch (weapon)
		{
		case 1:
			weaponPointer = new M21Rifle;
			break;
		case 2:
			weaponPointer = new M4Carbine;
			break;
		case 3:
			weaponPointer = new M9Pistol;
			break;
		default:
			weaponPointer = new M9Pistol;
			break;
		}

		switch (armor)
		{
		case 1:
			armorPointer = new BallisticShield;
			break;
		case 2:
			armorPointer = new Helmet;
			break;
		case 3:
			armorPointer = new BulletproofVest;
			break;
		default:
			armorPointer = new Helmet;
			break;
		}

		AddAgent(new Sniper(name, weaponPointer, armorPointer, { rand() % 40, rand() % 100 }));
	}
}

void GameManager::Loop()
{
	atomic<bool> programIsRunning{ true };
	thread readInputTask(ReadInputTask, ref(programIsRunning));

	while (_gameInProgress)
	{
		if (_gameIsRunning)
			Update();
		sleep_for(seconds(1));
	}

	ShowLogs();

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

	int count = 0;
	for (auto agent : _agents)
		if (!agent->IsDead())
			count++;
	if (count <= 1)
	{
		_gameInProgress = false;
		_gameIsRunning = false;
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

	if (_canShowLogs)
	{
		_canShowLogs = false;
		ShowLogs();
	}
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

void GameManager::AddLog(string log)
{
	GameManager::_logs.push_back(log);
}

void GameManager::ShowLogs()
{
	cout << "\tGAME DETAILS:\n";
	for (auto log : GameManager::_logs)
		cout << log << "\n";
}
