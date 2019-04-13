#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameManager.h"
#include "Sniper.h"

int main()
{
	srand(time(NULL));

	GameManager gameManager;

	Sniper s1("Marcus", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s2("Leon ", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s3("Sam", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s4("Max", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s5("Kane", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s6("Garrett", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });

	vector<IAgent*> agents{ &s1, &s2, &s3, &s4, &s5, &s6 };
	gameManager.AddAgents(agents);

	gameManager.Init();
	gameManager.Loop();
}