#include "Game.h"

Game::Game(HINSTANCE _hInstance, int _nCmdShow)
{
	hInstance = _hInstance;
	nCmdShow = _nCmdShow;
	window = new Window(hInstance, nCmdShow);
	fps = 60;
	mspf = 1000.0 / 60.0;
	deltaTime = 0;
	timer = new Timer();
	timer->Start();
	auto file_logger = spdlog::basic_logger_mt("file_logger", "logs/mylogfile.txt");

	file_logger->info("Game started");
}

void Game::Update() { 
	timer->Tick();
	auto file_logger = spdlog::get("file_logger");
	file_logger->info("Game update");
	deltaTime = timer->getDeltaTime();
	if (deltaTime >= mspf)
	{
		// log
		
	}
	else
	{
		// log
	}
}

void Game::LateUpdate() { }

void Game::Draw() { 
	auto file_logger = spdlog::get("file_logger");
	file_logger->info("Game draw");
}

bool Game::IsRunning() const
{
	MSG msg;
	while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		if (msg.message == WM_QUIT)
			return false;
	}
	return true;
}