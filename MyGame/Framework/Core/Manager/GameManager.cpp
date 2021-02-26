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
	fps = manager["fps"];
}
