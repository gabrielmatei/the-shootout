#pragma once

#include <chrono>
#include <thread>
#include <future>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include "Map.h"
#include "IAgent.h"
#include "Sniper.h"
#include "M21Rifle.h"
#include "M9Pistol.h"
#include "M4Carbine.h"
#include "BulletproofVest.h"
#include "Helmet.h"
#include "BallisticShield.h"
using namespace std::this_thread;
using namespace std::chrono;

class GameManager
{
private:
	static bool _gameInProgress;
	static bool _gameIsRunning;
	static bool _canShowLogs;

	int _round;
	Map _map;
	vector<IAgent*> _agents;
	static vector<string> _logs;

	void Update();
	void Display();
	void ShowAgentStats(AgentStats);
	void RemoveDeadAgents();
	static void ShowLogs();
	static void ReadInputTask(std::atomic<bool>&);
public:
	GameManager();
	~GameManager();
	void Init();
	void Start();
	void Loop();
	void AddAgent(IAgent*);
	void AddAgents(vector<IAgent*>);
	static void AddLog(string);
};