#include "TestGame.h"

TestGame::TestGame(HINSTANCE _hInstance, int _nCmdShow):Game(_hInstance, _nCmdShow)
{
	
	Sprite* sprite = new Sprite(manager->GetTexture("enemy.png"), 25, 24, 9, 248, true, 100);
	Sprite* sprite2 = new Sprite(manager->GetTexture("enemy.png"), 25, 30, 44, 242, true, 100);
	animation = new Animation();
	animation->AddSprite(sprite);
	animation->AddSprite(sprite2);

	object = new GameObject();
	object->AddAnimation(animation);
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
