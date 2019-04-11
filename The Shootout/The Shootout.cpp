#include "pch.h"
#include <iostream>
#include "GameManager.h"
#include "Sniper.h"

int main()
{
	GameManager gameManager;

	Sniper s1("A", { 3, 4 });
	Sniper s2("B", { 11, 17 });
	gameManager.AddAgent(&s1);
	gameManager.AddAgent(&s2);

	gameManager.Init();
	gameManager.Loop();
}