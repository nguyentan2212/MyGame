#include "WindowManager.h"

WindowManager::WindowManager() : Manager(PATH)
{
	Load();
}

WindowManager::WindowManager(const std::string& _filePath) : Manager(_filePath)
{
	Load();
}

void WindowManager::Load()
{
	title = manager["title"];
	className = manager["className"];
	width = manager["width"];
	height = manager["height"];
}
