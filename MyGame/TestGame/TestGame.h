#pragma once
#include "../Framework/Core/Game.h"
#include "TestGameManager.h"
#include "RunCommand.h"

class TestGame : public Game
{
public:
	TestGame(HINSTANCE _hInstance, int _nCmdShow);
	void Initialize();
	void Update();
	void LateUpdate();
	void Draw();
};