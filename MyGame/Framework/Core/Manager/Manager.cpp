#include "Manager.h"

Manager::Manager(const string& _filePath)
{
	filePath = _filePath;
	if (IsPathExist(filePath))
	{
		fstream f(filePath, ios::in);
		json managerFile;
		f >> managerFile;
		manager = managerFile["manager"];
	}
	else
	{
		// log
	}
}

bool Manager::IsPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}