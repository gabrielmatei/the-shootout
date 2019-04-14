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

	M21Rifle rifle("rifle", 14);
	BulletproofVest vest("vest", 40);

	Sniper s1("Marcus", rifle, vest, { rand() % 40, rand() % 100 });
	Sniper s2("Leon ", rifle, vest, { rand() % 40, rand() % 100 });
	Sniper s3("Sam", rifle, vest, { rand() % 40, rand() % 100 });
	Sniper s4("Max", rifle, vest, { rand() % 40, rand() % 100 });
	Sniper s5("Kane", rifle, vest, { rand() % 40, rand() % 100 });
	Sniper s6("Garrett", rifle, vest, { rand() % 40, rand() % 100 });

	vector<IAgent*> agents{ &s1, &s2, &s3, &s4, &s5, &s6 };
	gameManager.AddAgents(agents);

	gameManager.Init();
	gameManager.Loop();
}