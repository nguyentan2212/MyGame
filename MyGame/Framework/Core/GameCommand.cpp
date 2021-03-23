#include "GameCommand.h"

GameCommand::GameCommand() :name(""), chord(0) {}

GameCommand::GameCommand(const string& name, const int keyCode, const KeyState keyState) : name(name) {
	chord.push_back(KeyInfo(keyCode, keyState));
}

GameCommand::GameCommand(const string& name, const KeyInfo& keyInfo) : name(name) {
	chord.push_back(keyInfo);
}

GameCommand::GameCommand(const string& name, const vector<KeyInfo> keyInfos) : name(name), chord(keyInfos) {}