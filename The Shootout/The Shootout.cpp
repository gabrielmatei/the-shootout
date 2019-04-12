#include "pch.h"
#include <iostream>
#include "GameManager.h"
#include "Sniper.h"

int main()
{
	GameManager gameManager;

	Sniper s1("A", 7, { 3, 4 });
	Sniper s2("B", 9, { 11, 17 });
	Sniper s3("C", 6, { 38, 60 });
	Sniper s4("D", 8, { 30, 80 });
	gameManager.AddAgent(&s1);
	gameManager.AddAgent(&s2);
	gameManager.AddAgent(&s3);
	gameManager.AddAgent(&s4);

	gameManager.Init();
	gameManager.Loop();
}