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
	input = new KeyInput();
	RunCommand* runLeft = new RunCommand(objects[0], -1, "run left", VK_LEFT, KeyState::JustPressed);
	RunCommand* runRight = new RunCommand(objects[0], 1, "run right", VK_RIGHT, KeyState::JustPressed);
	RunCommand* indieLeft = new RunCommand(objects[0], 0, "indie left", VK_LEFT, KeyState::JustReleased);
	RunCommand* indieRight = new RunCommand(objects[0], 0, "indie right", VK_RIGHT, KeyState::JustReleased);
	input->AddCommand(runLeft);
	input->AddCommand(runRight);
	input->AddCommand(indieLeft);
	input->AddCommand(indieRight);
}

void TestGame::Update()
{
	input->AcquireInput();
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
