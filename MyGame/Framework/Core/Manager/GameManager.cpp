#include "GameManager.h"

GameManager::GameManager() : Manager(PATH)
{
	Load();
}

GameManager::GameManager(const string& _filePath) : Manager(_filePath)
{
	Load();
}

void GameManager::Load()
{
	auto mylogger = spdlog::get("mylogger");
	fps = manager["fps"];
	mylogger->info("Game manager properties load succeeded");
}
