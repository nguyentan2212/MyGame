#pragma once
#define GAME_PATH "manager/GameManager.json"
#include <string>
#include <fstream>
#include "../../Utility/json.hpp"
using namespace std;
using namespace nlohmann;

class Manager
{
public:
	Manager(const string& _filePath = GAME_PATH);

	int GetFPS() const 
	{
		return fps;
	}
protected:
	bool IsPathExist(const string& s);

	string filePath;
	json manager;

	int fps;
};