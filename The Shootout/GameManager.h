#pragma once

#include <chrono>
#include <thread>
#include "Map.h"
using namespace std::this_thread;
using namespace std::chrono;

class GameManager
{
private:
	int _round;

	Map _map;

	void Update();
	void Display();
public:
	GameManager();
	~GameManager();

	void Init();
	void Loop();
};