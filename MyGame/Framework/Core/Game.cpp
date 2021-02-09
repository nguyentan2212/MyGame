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
	Sprite* sprite = new Sprite(textureManager->GetTexture("enemy.png"), 25, 24, 9, 248, true, 100);
	Sprite* sprite2 = new Sprite(textureManager->GetTexture("enemy.png"), 25, 30, 44, 242, true, 100);
	animation = new Animation();
	animation->AddSprite(sprite);
	animation->AddSprite(sprite2);
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

void Game::LateUpdate() {
	animation->UpdateFrame(deltaTime);
}

void Game::Draw() { 
	window->BeginDraw();
	window->Draw(animation->GetCurrentFrame(), 30, 10);
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