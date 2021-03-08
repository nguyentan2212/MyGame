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

void Manager::Initialize()
{
	fps = manager["fps"];
	title = manager["title"];
	width = manager["width"];
	height = manager["height"];
}

void Manager::LoadGraphic(DrawDevice* _drawDevice)
{
	d3ddv = _drawDevice->GetDevice();
	for (auto& element : manager["textures"])
	{
		string name = element["name"];
		json color = element["transparentColor"];
		int red = color["red"];
		int green = color["green"];
		int blue = color["blue"];
		LPDIRECT3DTEXTURE9 textureImage = LoadTexture("textures/" + name, D3DCOLOR_XRGB(red, green, blue));
		Texture* texture = new Texture(textureImage, D3DCOLOR_XRGB(red, green, blue));
		textures.insert(make_pair(name, texture));
	}

	for (auto& element : manager["animations"])
	{
		string name = element["name"];
		Animation* animation = new Animation();
		for (auto& item : element["sprites"])
		{
			Texture* texture = GetTexture(item["texture"]);
			Sprite* sprite = new Sprite(texture, item["width"], item["height"], item["x"], item["y"], item["flip"], item["time"]);
			animation->AddSprite(sprite);
		}
		animations.insert(make_pair(name, animation));
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