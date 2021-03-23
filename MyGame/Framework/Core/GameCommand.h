#pragma once
#include <vector>
#include <string>
#include "KeyInfo.h"
using namespace std;

class GameCommand
{
public:
	GameCommand();
	GameCommand(const string& name, const int keyCode, const KeyState keyState);
	GameCommand(const string& name, const KeyInfo& keyInfo);
	GameCommand(const string& name, const vector<KeyInfo> keyInfos);
	vector<KeyInfo> GetChord() const { return chord; }
	virtual void Execute() = 0;
	virtual bool CanExecute() = 0;

private:
	string name;
	vector<KeyInfo> chord;
};
