#include "Texture.h"

Texture::Texture(LPDIRECT3DTEXTURE9 _textureImage)
{
	textureImage = _textureImage;
	transparentColor = D3DCOLOR_XRGB(255, 255, 255);
}

Texture::Texture(LPDIRECT3DTEXTURE9 _textureImage, D3DCOLOR _transparentColor)
{
	textureImage = _textureImage;
	transparentColor = _transparentColor;
}
