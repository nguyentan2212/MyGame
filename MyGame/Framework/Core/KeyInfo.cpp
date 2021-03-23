#include "KeyInfo.h"

KeyInfo::KeyInfo() : keyCode(0), keyState(KeyState::JustReleased) {}

KeyInfo::KeyInfo(int keyCode, KeyState keyState) : keyCode(keyCode), keyState(keyState) {}