#include "pch.h"
#include <iostream>
#include "GameManager.h"

int main()
{
	GameManager gameManager;

	gameManager.Init();
	gameManager.Loop();
}