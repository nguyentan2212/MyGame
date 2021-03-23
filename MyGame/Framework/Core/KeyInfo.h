#pragma once
#include "Enums.h"

class KeyInfo 
{
public:
	KeyInfo();
	KeyInfo(int keyCode, KeyState keyState);
	~KeyInfo(){}
private:
	int keyCode;
	KeyState keyState;
};