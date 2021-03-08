#pragma once
#define GAME_PATH "manager/GameManager.json"
#include <string>
#include <fstream>
#include <d3d9.h>
#include <d3dx9.h>
#include <map>
#include "../../Graphic/DrawDevice.h"
#include "../../Graphic/Texture.h"

#include "../../Utility/json.hpp"
#include "../../Utility/StringConverter.h"

using namespace std;
using namespace nlohmann;

class Manager
{
public:
	Manager(const string& _filePath = GAME_PATH);
	void Initialize();
	void LoadGraphic(DrawDevice* _drawDevice);
	Texture* GetTexture(string name);

	int GetFPS() { return fps; }
	std::string GetTitle() { return title; }
	int GetWidth() { return width; }
	int GetHeight() { return height; }
protected:
	bool IsPathExist(const string& s);
	LPDIRECT3DTEXTURE9 LoadTexture(const string& texturePath, D3DCOLOR transparentColor = D3DCOLOR_XRGB(255, 255, 255));
	
	string filePath;
	json manager;

	int fps;
	std::string title;
	int width;
	int height;
	map<string, Texture*> textures;
	LPDIRECT3DDEVICE9 d3ddv;
	DrawDevice* drawDevice;
};