#pragma once
#include <string>
#include <vector>
#include "../Framework/Core/Manager.h"

class TestGameManager : public Manager
{
public:
	TestGameManager(const string& _filePath = GAME_PATH);
	void LoadWindow();
	void LoadGraphic(DrawDevice* _drawDevice);
	vector<GameObject*> LoadGameObject();

private:
	GameObject* makeObject(int type);
};