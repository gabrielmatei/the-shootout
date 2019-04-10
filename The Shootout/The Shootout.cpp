#include "pch.h"
#include <iostream>
#include "GameManager.h"
#include "Sniper.h"

int main()
{
	GameManager gameManager;

	gameManager.Init();

	Sniper s1("A", 100);
	Sniper s2("B", 120);
	gameManager.AddAgent(&s1);
	gameManager.AddAgent(&s2);

	gameManager.Loop();
}