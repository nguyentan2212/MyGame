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

Texture* TextureManager::GetTexture(string name)
{
	if (textures.find(name) != textures.end())
	{
		return textures[name];
	}
	return nullptr;
}

void TextureManager::Load()
{
	auto texturesJson = manager["textures"];
	string folder = manager["folder"];
	for (auto& element : texturesJson)
	{
		string name = element["name"];
		json color = element["transparentColor"];
		int red = color["red"];
		int green = color["green"];
		int blue = color["blue"];
		LPDIRECT3DTEXTURE9 textureImage = LoadTexture(folder + name, D3DCOLOR_XRGB(red, green, blue));
		Texture* texture = new Texture(textureImage, D3DCOLOR_XRGB(red, green, blue));
		textures.insert(make_pair(name, texture));
	}
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(const string& texturePath, D3DCOLOR transparentColor)
{
	D3DXIMAGE_INFO info;
	LPDIRECT3DTEXTURE9 texture;
	wstring path = ultility::StringConverter::s2ws(texturePath);
	LPCWSTR lpPath = path.c_str();
	HRESULT result = D3DXGetImageInfoFromFile(lpPath, &info);
	if (result != D3D_OK)
	{
		
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
		
		return NULL;
	}
	
	return texture;
}
