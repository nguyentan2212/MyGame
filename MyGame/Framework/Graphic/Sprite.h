#pragma once
#include "Texture.h"

class Sprite
{
public:
	Sprite(Texture* _texture, int _width, int _height, int _x, int _y, bool _flip);

	int width;
	int height;
	int x;
	int y;
	bool flip;
	Texture* texture;
	RECT GetRect();
private:
	
};