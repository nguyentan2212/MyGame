#include "Manager.h"

Manager::Manager(const string& _filePath)
{
	filePath = _filePath;
	auto mylogger = spdlog::get("mylogger");
	if (IsPathExist(filePath))
	{
		fstream f(filePath, ios::in);
		json managerFile;
		f >> managerFile;
		manager = managerFile["manager"];
		mylogger->info("Manager file load succeeded. File path: " + _filePath);
	}
	else
	{
		// log
		mylogger->error("Manager file not found. File path: "+_filePath);
	}
}

bool Manager::IsPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}