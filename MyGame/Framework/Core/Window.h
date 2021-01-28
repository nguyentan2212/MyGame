#pragma once
#define ICON 107
#define ICONSMALL 108 
#define TITLE "main window"
#define WIN_CLASS "windowClass"
#define WIDTH 900
#define HEIGHT 700
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "../Utility/StringConverter.h"
#include "./Manager/WindowManager.h"

using namespace std;

class Window
{
public:
    Window(HINSTANCE _hInstance, int _nCmdShow);
    ~Window();
    void Update();
    void BeginDraw();
    void Draw();
    void EndDraw();
    bool IsOpen() const;

    static LRESULT CALLBACK msgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
    HWND mainWindow;
    HINSTANCE hInstance;
    int nCmdShow;
    WindowManager* manager;
    LPCWSTR lpWindowTitle;
    LPCWSTR lpWindowClass;
    int width;
    int height;
    void Register(); // Registers the window class
    void Init(); // Saves instance handle and creates main window
};

typedef Window* LPWINDOW;