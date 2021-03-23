#include "Game.h"

Game::Game(HINSTANCE _hInstance, int _nCmdShow)
{
	deltaTime = 0;

	hInstance = _hInstance;
	nCmdShow = _nCmdShow;

	timer = new Timer();
	timer->Start();
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