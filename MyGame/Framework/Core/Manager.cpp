#include "Manager.h"

Manager::Manager(const string& _filePath)
{
	filePath = _filePath;
	if (IsPathExist(filePath))
	{
		fstream f(filePath, ios::in);
		json managerFile;
		f >> managerFile;
		manager = managerFile["manager"];
	}
	else
	{
		// log
	}
}

LPDIRECT3DTEXTURE9 Manager::LoadTexture(const string& texturePath, D3DCOLOR transparentColor)
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

Texture* Manager::GetTexture(string name)
{
	if (textures.find(name) != textures.end())
	{
		return textures[name];
	}
	return nullptr;
}

Animation* Manager::GetAnimation(string name)
{
	if (animations.find(name) != animations.end())
	{
		return animations[name];
	}
	return nullptr;
}

bool Manager::IsPathExist(const std::string& s)
{
	struct stat buffer;
	return (stat(s.c_str(), &buffer) == 0);
}