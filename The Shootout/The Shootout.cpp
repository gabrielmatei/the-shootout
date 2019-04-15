#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "GameManager.h"
#include "Sniper.h"
#include "M21Rifle.h"
#include "BulletproofVest.h"

int main()
{
	srand(time(NULL));

	GameManager gameManager;

	Sniper s1("Marcus", new M21Rifle, new BulletproofVest, { rand() % 40, rand() % 100 });
	Sniper s2("Leon ", new M21Rifle, new BulletproofVest, { rand() % 40, rand() % 100 });
	Sniper s3("Sam", new M21Rifle, new BulletproofVest, { rand() % 40, rand() % 100 });
	Sniper s4("Max", new M21Rifle, new BulletproofVest, { rand() % 40, rand() % 100 });
	Sniper s5("Kane", new M21Rifle, new BulletproofVest, { rand() % 40, rand() % 100 });
	Sniper s6("Garrett", new M21Rifle, new BulletproofVest, { rand() % 40, rand() % 100 });

	vector<IAgent*> agents{ &s1, &s2, &s3, &s4, &s5, &s6 };
	gameManager.AddAgents(agents);

	gameManager.Init();
	gameManager.Loop();
}