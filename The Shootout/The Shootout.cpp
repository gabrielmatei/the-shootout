#include "pch.h"
#include <iostream>
#include "GameManager.h"
#include "Sniper.h"

int main()
{
	GameManager gameManager;

	Sniper s1("Marcus", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s2("Leon ", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s3("Sam", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s4("Max", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s5("Kane", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	Sniper s6("Garrett", rand() % 10 + 1, rand() % 50 + 1, { rand() % 40, rand() % 100 });
	gameManager.AddAgent(&s1);
	gameManager.AddAgent(&s2);
	gameManager.AddAgent(&s3);
	gameManager.AddAgent(&s4);
	gameManager.AddAgent(&s5);
	gameManager.AddAgent(&s6);

	gameManager.Init();
	gameManager.Loop();
}