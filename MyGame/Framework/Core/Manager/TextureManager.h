#pragma once
#define PATH "manager/TextureManager.json"
#include <d3d9.h>
#include <d3dx9.h>
#include <map>
#include <spdlog/spdlog.h>
#include "../../Utility/json.hpp"
#include "../../Utility/StringConverter.h"
#include "Manager.h"
#include "../../Graphic/DrawDevice.h"
#include "../../Graphic/Texture.h"

using namespace std;

class TextureManager : Manager
{
public:
	TextureManager(DrawDevice* _drawDevice);
	TextureManager(const string& _filePath, DrawDevice* _drawDevice);
	Texture* GetTexture(string name);

private:
	void Load();
	LPDIRECT3DTEXTURE9 LoadTexture(const string& texturePath, D3DCOLOR transparentColor = D3DCOLOR_XRGB(255, 255, 255));
	map<string, Texture*> textures;
	LPDIRECT3DDEVICE9 d3ddv;
	DrawDevice* drawDevice;
};