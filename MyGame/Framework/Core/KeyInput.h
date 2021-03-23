#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <WinUser.h>
#include <array>
#include <vector>
#include "GameCommand.h"
using namespace std;

class KeyInput
{
public:
	KeyInput();
	~KeyInput();
	void AcquireInput();
	void AddCommand(GameCommand* command);
private:
	array<BYTE, 256> keyboardStateCurrent;
	array<BYTE, 256> keyboardStatePrevious;
	vector<GameCommand*> activeCommands;
	vector<GameCommand*> commands;
	void getKeyBoardState();
	bool isPressed(int keyCode) const { return (GetAsyncKeyState(keyCode) & 0x8000) ? 1 : 0; }
	KeyState getKeyState(int keyCode) const;
	void update();
	void executeCommands();
};