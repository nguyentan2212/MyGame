#pragma once
#define PATH "manager/WindowManager.json"
#include <spdlog/spdlog.h>
#include "../../Utility/json.hpp"
#include "Manager.h"

using namespace std;
class WindowManager : Manager
{
public:
	WindowManager();
	WindowManager(const string& _filePath);

	string title;
	string className;
	int width;
	int height;
private:
	void Load();
};