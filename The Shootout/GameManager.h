#pragma once

#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Map.h"
#include "IAgent.h"
using namespace std::this_thread;
using namespace std::chrono;

class GameManager
{
private:
	int _round;

	Map _map;
	vector<IAgent*> _agents;

	void Update();
	void Display();
	void ShowAgentStats(AgentStats);
	void RemoveDeadAgents();
public:
	GameManager();
	~GameManager();

	void Init();
	void Loop();

	void AddAgent(IAgent*);
	void AddAgents(vector<IAgent*>);
};