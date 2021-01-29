#include "DrawDevice.h"

DrawDevice::DrawDevice(HWND window)
{
	auto mylogger = spdlog::get("mylogger");

	LPDIRECT3D9 d3d = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;

	RECT r;
	GetClientRect(window, &r);

	d3dpp.BackBufferHeight = r.bottom + 1;
	d3dpp.BackBufferWidth = r.right + 1;
	d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		window,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddv);

	if (d3ddv == NULL)
	{
		mylogger->error("Draw device constructor failed");
		return;
	}
	d3ddv->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);
	D3DXCreateSprite(d3ddv, &spriteHandler);
	mylogger->info("Draw device constructor succeeded");
}

DrawDevice::~DrawDevice()
{
	d3ddv->Release();    // close and release the 3D device
}

void DrawDevice::Begin()
{
	d3ddv->BeginScene();
	d3ddv->ColorFill(backBuffer, NULL, D3DCOLOR_XRGB(255, 255, 255));
}

void DrawDevice::Draw(D3DXVECTOR3 drawPosition, LPDIRECT3DTEXTURE9 texture, RECT resource)
{
	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
	spriteHandler->Draw(texture, &resource, NULL, &drawPosition, D3DCOLOR_XRGB(255, 255, 255));
	spriteHandler->End();
}

void DrawDevice::End()
{
	d3ddv->EndScene();
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

LPDIRECT3DDEVICE9 DrawDevice::GetDevice()
{
	return d3ddv;
}
