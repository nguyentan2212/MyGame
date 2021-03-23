#pragma once
#include "Enums.h"

class KeyInfo 
{
public:
	KeyInfo();
	KeyInfo(int keyCode, KeyState keyState);
	~KeyInfo(){}
	int GetKeyCode() const { return keyCode; }
	KeyState GetKeyState() const { return keyState; }
private:
	int keyCode;
	KeyState keyState;
};