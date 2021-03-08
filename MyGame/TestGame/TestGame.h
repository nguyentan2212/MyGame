#pragma once
#include "../Framework/Core/Game.h"

class TestGame : public Game
{
public:
	TestGame(HINSTANCE _hInstance, int _nCmdShow);
	void Update();
	void LateUpdate();
	void Draw();

private:
	GameObject* object;
	Animation* animation;
};