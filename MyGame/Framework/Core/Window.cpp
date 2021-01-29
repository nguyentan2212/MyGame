#include "Window.h"

Window::Window(HINSTANCE _hInstance, int _nCmdShow)
{
	manager = new WindowManager();
	wstring ws = ultility::StringConverter::s2ws(manager->title);
	lpWindowTitle = ws.c_str();
	wstring ws2 = ultility::StringConverter::s2ws(manager->className);
	lpWindowClass = ws2.c_str();
	width = manager->width;
	height = manager->height;
	
	hInstance = _hInstance;
	nCmdShow = _nCmdShow;

	Register();
	Init();
	auto mylogger = spdlog::get("mylogger");
	device = new DrawDevice(mainWindow);
	mylogger->info("Window constructor end");
}

void Window::Register()
{
	auto mylogger = spdlog::get("mylogger");
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
		mylogger->error("Window register failed");
		return; // log
	}
	mylogger->info("Window register succeeded");
	return; // log
}

void Window::Init()
{
	auto mylogger = spdlog::get("mylogger");
	mainWindow = CreateWindowW(lpWindowClass, lpWindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);
	if (!mainWindow)
	{
		mylogger->error("Window initialize failed");
		return; // log
	}
	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);
	mylogger->info("Window initialize succeeded");
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
}

void Window::Draw()
{
}

void Window::EndDraw()
{
}

bool Window::IsOpen() const
{
	return true;
}

DrawDevice* Window::GetDrawDevice()
{
	return device;
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