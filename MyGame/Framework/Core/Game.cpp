#include "Game.h"

Game::Game(HINSTANCE _hInstance, int _nCmdShow)
{
	manager = new GameManager();
	fps = manager->fps;
	mspf = 1000.0 / fps;
	deltaTime = 0;

	hInstance = _hInstance;
	nCmdShow = _nCmdShow;
	window = new Window(hInstance, nCmdShow);

	textureManager = new TextureManager(window->GetDrawDevice());

	input = new KeyInput(hInstance, window->GetWindow());

	timer = new Timer();
	timer->Start();
}

void Game::Update() { 
	input->CaptureInput();
	timer->Tick();
	deltaTime = timer->getDeltaTime();
	DebugOut(L"[INFO] deltaTime: %f, mspf: %f\n", deltaTime, mspf);
	if (deltaTime >= mspf)
	{
		// update
		object->Update(deltaTime);
	}
	else
	{
		// sleep
		long sleepTime = (long)deltaTime - (long)mspf;
		sleepTime = sleepTime < 0 ? 0 : sleepTime;
		Sleep(sleepTime);
	}
	if (input->IsKeyPress(DIK_LEFTARROW))
	{
		object->velocity = Vector2D(1, 0);
	}
	if (input->IsKeyPress(DIK_RIGHTARROW))
	{
		object->velocity = Vector2D(-1, 0);
	}
	
}

void Game::LateUpdate() {
}

void Game::Draw() { 
	window->BeginDraw();
	window->Draw(object->GetAnimation(0)->GetCurrentFrame(), object->position.GetX(), object->position.GetY());
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