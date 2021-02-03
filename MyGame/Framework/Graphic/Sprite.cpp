#include "Sprite.h"

Sprite::Sprite(Texture* _texture, int _width, int _height, int _x, int _y, bool _flip)
{
	texture = _texture;
	width = _width;
	height = _height;
	x = _x;
	y = _y;
	flip = _flip;
}

RECT Sprite::GetRect()
{
	RECT source;
	source.left = x;
	source.top = y;
	source.right = x + width;
	source.bottom = y + height;
	return source;
}
