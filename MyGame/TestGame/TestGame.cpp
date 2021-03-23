#include "TestGame.h"

TestGame::TestGame(HINSTANCE _hInstance, int _nCmdShow):Game(_hInstance, _nCmdShow)
{

}

void TestGame::Initialize()
{
	manager = new TestGameManager();
	manager->LoadWindow();
	fps = manager->GetFPS();
	mspf = 1000.0 / fps;

	window = new Window(hInstance, nCmdShow, manager->GetTitle(), manager->GetWidth(), manager->GetHeight());

	manager->LoadGraphic(window->GetDrawDevice());

	objects = manager->LoadGameObject();
}

void TestGame::Update()
{
	
	timer->Tick();
	deltaTime = timer->getDeltaTime();
	DebugOut(L"[INFO] deltaTime: %f, mspf: %f\n", deltaTime, mspf);
	if (deltaTime >= mspf)
	{
		// update
		objects[0]->Update(deltaTime);
	}
	else
	{
		// sleep
		long sleepTime = (long)deltaTime - (long)mspf;
		sleepTime = sleepTime < 0 ? 0 : sleepTime;
		Sleep(sleepTime);
	}

}

void TestGame::LateUpdate()
{
}

void TestGame::Draw()
{
	window->BeginDraw();
	window->Draw(objects[0]->GetAnimation(0)->GetCurrentFrame(), objects[0]->position.GetX(), objects[0]->position.GetY());
	window->EndDraw();
}
