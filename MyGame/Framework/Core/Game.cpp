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
	auto mylogger = spdlog::basic_logger_mt("mylogger", "logs/mylogfile.txt");
	mylogger->info("***********************************");
	mylogger->info("Game started");
	manager = new GameManager();
}

void Game::Update() { 
	timer->Tick();
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