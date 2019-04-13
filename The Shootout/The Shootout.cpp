#include "pch.h"
#include <iostream>
#include "GameManager.h"
#include "Sniper.h"

int main()
{
	GameManager gameManager;

	Sniper s1("A", 7, 30, { 3, 4 });
	Sniper s2("B", 9, 100, { 11, 17 });
	Sniper s3("C", 6, 40, { 38, 60 });
	Sniper s4("D", 8, 50, { 30, 80 });
	gameManager.AddAgent(&s1);
	gameManager.AddAgent(&s2);
	gameManager.AddAgent(&s3);
	gameManager.AddAgent(&s4);

	gameManager.Init();
	gameManager.Loop();
}