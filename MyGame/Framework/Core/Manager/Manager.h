#pragma once
#include <string>
#include <fstream>
#include <sys/stat.h>
#include <spdlog/spdlog.h>
#include "../../Utility/json.hpp"
using namespace std;
using namespace nlohmann;

class Manager
{
public:
	Manager(const string& _filePath);

protected:
	bool IsPathExist(const string& s);
	virtual void Load() {}

	string filePath;
	json manager;
};