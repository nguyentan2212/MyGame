#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Texture 
{
public:
	Texture(LPDIRECT3DTEXTURE9 _textureImage);
	Texture(LPDIRECT3DTEXTURE9 _textureImage, D3DCOLOR _transparentColor);
	LPDIRECT3DTEXTURE9 textureImage;
	D3DCOLOR transparentColor;
};