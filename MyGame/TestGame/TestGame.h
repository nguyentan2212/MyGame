#pragma once
#include "../Framework/Core/Game.h"
#include "TestGameManager.h"

class TestGame : public Game
{
public:
	TestGame(HINSTANCE _hInstance, int _nCmdShow);
	void Initialize();
	void Update();
	void LateUpdate();
	void Draw();
	

};