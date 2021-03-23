#include "RunCommand.h"

RunCommand::RunCommand(GameObject* receiver, int direction) : GameCommand()
{
	this->receiver = receiver;
	this->direction = direction;
}

RunCommand::RunCommand(GameObject* receiver, int direction, const string& name, const int keyCode, const KeyState keyState) : GameCommand(name, keyCode, keyState)
{
	this->receiver = receiver;
	this->direction = direction;
}

RunCommand::RunCommand(GameObject* receiver, int direction, const string& name, const KeyInfo& keyInfo) : GameCommand(name, keyInfo)
{
	this->receiver = receiver;
	this->direction = direction;
}

RunCommand::RunCommand(GameObject* receiver, int direction, const string& name, const vector<KeyInfo> keyInfos) : GameCommand(name, keyInfos)
{
	this->receiver = receiver;
	this->direction = direction;
}

void RunCommand::Execute()
{
	if (CanExecute() == false)
		return;
	receiver->velocity = Vector2D(0.1 * direction, 0);
}

bool RunCommand::CanExecute()
{
	return true;
}
