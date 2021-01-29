#include "TextureManager.h"

TextureManager::TextureManager(DrawDevice* _drawDevice) : Manager(PATH)
{
	drawDevice = _drawDevice;
	d3ddv = drawDevice->GetDevice();
	Load();
}

TextureManager::TextureManager(const string& _filePath, DrawDevice* _drawDevice) : Manager(_filePath)
{
	drawDevice = _drawDevice;
	d3ddv = drawDevice->GetDevice();
	Load();
}

LPDIRECT3DTEXTURE9 TextureManager::GetTexture(string name)
{
	return LPDIRECT3DTEXTURE9();
}

void TextureManager::Load()
{
	auto mylogger = spdlog::get("mylogger");
	auto texturesJson = manager["textures"];
	string folder = manager["folder"];
	for (auto& element : texturesJson)
	{
		string name = element["name"];
		LPDIRECT3DTEXTURE9 texture = LoadTexture(folder + name);
		textures.insert(make_pair(name, texture));
	}
	mylogger->info("Texture manager properties load succeeded");
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(const string& texturePath, D3DCOLOR transparentColor)
{
	auto mylogger = spdlog::get("mylogger");
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 texture;
	wstring path = ultility::StringConverter::s2ws(texturePath);
	LPCWSTR lpPath = path.c_str();
	HRESULT result = D3DXGetImageInfoFromFile(lpPath, &info);
	if (result != D3D_OK)
	{
		mylogger->error("Get image texture failed. Texture path: " + texturePath);
		return NULL;
	}
	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		lpPath,						        // Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,			        // Transparent color
		&info,
		NULL,
		&texture);						    // Created texture pointer
	
	if (result != D3D_OK)
	{
		mylogger->error("Load texture failed. Texture path: " + texturePath);
		return NULL;
	}
	mylogger->info("Load texture succeeded. Texture path: " + texturePath);
	return texture;
}
