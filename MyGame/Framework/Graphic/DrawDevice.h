#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class DrawDevice
{
public:
	DrawDevice(HWND window);
	~DrawDevice();
	void Begin();
	void Draw(D3DXVECTOR3 drawPosition, LPDIRECT3DTEXTURE9 texture, RECT resource, bool flip);
	void End();
	LPDIRECT3DDEVICE9 GetDevice();

private:
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object
	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;
};