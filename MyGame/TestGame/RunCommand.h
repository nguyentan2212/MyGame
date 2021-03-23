#pragma once
#include "../Framework/Core/GameCommand.h"
#include "../Framework/Core/GameObject.h"

class RunCommand : public GameCommand
{
public:
	RunCommand(GameObject* receiver, int direction);
	RunCommand(GameObject* receiver, int direction, const string& name, const int keyCode, const KeyState keyState);
	RunCommand(GameObject* receiver, int direction, const string& name, const KeyInfo& keyInfo);
	RunCommand(GameObject* receiver, int direction, const string& name, const vector<KeyInfo> keyInfos);
	void Execute();
	bool CanExecute();
private:
	GameObject* receiver;
	int direction;
};