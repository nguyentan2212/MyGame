#include "KeyInput.h"

KeyInput::KeyInput()
{
	keyboardStateCurrent.fill(0);
	keyboardStatePrevious.fill(0);
}

KeyInput::~KeyInput()
{
	for (auto x : commands)
		delete x;
	commands.clear();

	for (auto x : activeCommands)
		delete x;
	activeCommands.clear();
}

void KeyInput::AcquireInput()
{
	getKeyBoardState();
	update();
	executeCommands();
}

void KeyInput::AddCommand(GameCommand* command)
{
	commands.push_back(command);
}

void KeyInput::getKeyBoardState()
{
	keyboardStatePrevious = keyboardStateCurrent;
	for (int i = 0; i < 256; i++)
		keyboardStateCurrent[i] = isPressed(i);
}

KeyState KeyInput::getKeyState(int keyCode) const
{
	if (keyboardStatePrevious[keyCode] == 1)
		if (keyboardStateCurrent[keyCode] == 1)
			return KeyState::StillPressed;
		else
			return KeyState::JustReleased;
	else
		if (keyboardStateCurrent[keyCode] == 1)
			return KeyState::JustPressed;
		else
			return KeyState::StillReleased;
}

void KeyInput::update()
{
	bool isActive = false;
	activeCommands.clear();

	for (auto x : commands) 
	{
		isActive = true;
		for (auto y : x->GetChord())
		{
			if (getKeyState(y.GetKeyCode()) != y.GetKeyState())
			{
				isActive = false;
				break;
			}
		}
		if (isActive)
			activeCommands.push_back(x);
	}
}

void KeyInput::executeCommands()
{
	for (auto x : activeCommands)
	{
		x->Execute();
	}
}
