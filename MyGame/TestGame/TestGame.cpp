#include "TestGame.h"

TestGame::TestGame(HINSTANCE _hInstance, int _nCmdShow):Game(_hInstance, _nCmdShow)
{
	GameObject* object = new GameObject();
	object->AddAnimation(manager->GetAnimation("enemy fly to right"));
	object->position = Vector2D(30, 20);

}

void TestGame::Update()
{
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
		object->velocity = Vector2D(0.1, 0);
	}
	if (input->IsKeyPress(DIK_RIGHTARROW))
	{
		object->velocity = Vector2D(-0.1, 0);
	}

}

void TestGame::LateUpdate()
{
}

void TestGame::Draw()
{
	window->BeginDraw();
	window->Draw(object->GetAnimation(0)->GetCurrentFrame(), object->position.GetX(), object->position.GetY());
	window->EndDraw();
}
