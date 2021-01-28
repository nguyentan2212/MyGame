#include "WindowManager.h"

WindowManager::WindowManager() : Manager(DEFAULT_PATH)
{
	Load();
}

WindowManager::WindowManager(const std::string& _filePath) : Manager(_filePath)
{
	Load();
}

void WindowManager::Load()
{
	auto mylogger = spdlog::get("mylogger");
	title = manager["title"];
	className = manager["className"];
	width = manager["width"];
	height = manager["height"];
	mylogger->info("Window manager properties load succeeded");
}
