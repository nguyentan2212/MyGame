#include "TestGameManager.h"

TestGameManager::TestGameManager(const string& _filePath) :Manager(_filePath)
{

}

void TestGameManager::LoadWindow()
{
	fps = manager["fps"];
	title = manager["title"];
	width = manager["width"];
	height = manager["height"];
}

void TestGameManager::LoadGraphic(DrawDevice* _drawDevice)
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

vector<GameObject*> TestGameManager::LoadGameObject()
{
	vector<GameObject*> objects;
	for (auto& element : manager["gameObjects"])
	{
		GameObject* object = makeObject(element["type"]);
		for (auto& animation : element["animations"])
		{
			object->AddAnimation(GetAnimation(animation["name"]));
		}
		object->position = Vector2D(element["position"]["x"], element["position"]["y"]);
		objects.push_back(object);
	}
	return objects;
}

GameObject* TestGameManager::makeObject(int type)
{
	switch (type)
	{
	default:
		return new GameObject();
	}
}
