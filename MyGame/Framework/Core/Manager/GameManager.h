#pragma once
#define DEFAULT_PATH "manager/GameManager.json"
#include <spdlog/spdlog.h>
#include "../../Utility/json.hpp"
#include "Manager.h"

class GameManager : public Manager
{
public:
	GameManager();
	GameManager(const string& _filePath);

	int fps;
private:
	void Load();
};