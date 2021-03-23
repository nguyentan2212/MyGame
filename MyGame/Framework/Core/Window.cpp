#include "Window.h"

Window::Window(HINSTANCE _hInstance, int _nCmdShow, std::string title, int _width, int _height)
{
	wstring ws = ultility::StringConverter::s2ws(title);
	lpWindowTitle = ws.c_str();
	width = _width;
	height = _height;
	
	hInstance = _hInstance;
	nCmdShow = _nCmdShow;

	Register();
	Init();
	
	device = new DrawDevice(mainWindow);
}

void Window::Register()
{
	WNDCLASSEXW wcex;
	
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = msgProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(ICON));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"MyGame";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(ICONSMALL));

	if (!RegisterClassEx(&wcex))
	{
		
		return; // log
	}

	return; // log
}

void Window::Init()
{

	mainWindow = CreateWindowW(L"MyGame", lpWindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);
	if (!mainWindow)
	{

		return; // log
	}
	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);

	return; // log
}

Window::~Window()
{
	if (mainWindow)
		mainWindow = NULL;
	if (hInstance)
		hInstance = NULL;
}

void Window::Update()
{
}

void Window::BeginDraw()
{
	device->Begin();
}

void Window::Draw(Sprite* sprite, double x, double y)
{
	if (sprite->flip)
	{
		x = x * -1 - sprite->width;
	}
	D3DXVECTOR3 pos(x, y, 0);
	RECT source = sprite->GetRect();
	Texture* texture = sprite->texture;
	device->Draw(pos,texture->textureImage, source, sprite->flip);
}

void Window::EndDraw()
{
	device->End();
}

bool Window::IsOpen() const
{
	return true;
}

DrawDevice* Window::GetDrawDevice()
{
	return device;
}

HWND Window::GetWindow() const
{
	return mainWindow;
}



LRESULT Window::msgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}