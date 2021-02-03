#include "Game.h"

Game::Game(HINSTANCE _hInstance, int _nCmdShow)
{
	auto mylogger = spdlog::basic_logger_mt("mylogger", "logs/mylogfile.txt");
	mylogger->info("***********************************");
	mylogger->info("Game started");

	manager = new GameManager();
	fps = manager->fps;
	mspf = 1000.0 / fps;
	deltaTime = 0;

	hInstance = _hInstance;
	nCmdShow = _nCmdShow;
	window = new Window(hInstance, nCmdShow);
	
	textureManager = new TextureManager(window->GetDrawDevice());
	sprite = new Sprite(textureManager->GetTexture("enemy.png"), 22, 27, 10, 187, true);
	timer = new Timer();
	timer->Start();
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
	window->BeginDraw();
	window->Draw(sprite, 22, 0);
	window->EndDraw();
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