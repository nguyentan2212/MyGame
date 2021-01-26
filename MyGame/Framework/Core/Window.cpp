#include "Window.h"

Window::Window(HINSTANCE _hInstance, int _nCmdShow)
{
	lpWindowName = ultility::StringConverter::s2lpcws(NAME);
	lpWindowClass = ultility::StringConverter::s2lpcws(WIN_CLASS);
	width = WIDTH;
	height = HEIGHT;
	hInstance = _hInstance;
	nCmdShow = _nCmdShow;
	Register();
	Init();
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
	wcex.lpszClassName = lpWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(ICONSMALL));

	if (!RegisterClassEx(&wcex))
	{
		return; // log
	}
	return;
}

void Window::Init()
{
	mainWindow = CreateWindowW(lpWindowClass, lpWindowName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);
	if (!mainWindow)
	{
		return;
	}
	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);
	return;
}

Window::~Window()
{
	if (mainWindow)
		mainWindow = NULL;
	if (hInstance)
		hInstance = NULL;
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