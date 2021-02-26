#pragma once
#include <string>
#include <fstream>
#include "../../Utility/json.hpp"
using namespace std;
using namespace nlohmann;

class Manager
{
public:
	Manager(const string& _filePath);

protected:
	bool IsPathExist(const string& s);

	string filePath;
	json manager;
};