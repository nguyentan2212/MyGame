#include "Game.h"

Game::Game(HINSTANCE _hInstance, int _nCmdShow)
{
	manager = new Manager();
	manager->Initialize();
	fps = manager->GetFPS();
	mspf = 1000.0 / fps;
	deltaTime = 0;

	hInstance = _hInstance;
	nCmdShow = _nCmdShow;
	window = new Window(hInstance, nCmdShow, manager->GetTitle(), manager->GetWidth(), manager->GetHeight());

	manager->LoadTexture(window->GetDrawDevice());

	input = new KeyInput(hInstance, window->GetWindow());

	timer = new Timer();
	timer->Start();
}

void Game::Update() { 
	
}

void Game::LateUpdate() {
}

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