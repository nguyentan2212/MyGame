#pragma once
#define ICON 107
#define ICONSMALL 108
#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "../Utility/StringConverter.h"
#include "../Graphic/DrawDevice.h"
#include "../Graphic/Sprite.h"

using namespace std;

class Window
{
public:
    Window(HINSTANCE _hInstance, int _nCmdShow, std::string title, int _width, int _height);
    ~Window();
    void Update();
    void BeginDraw();
    void Draw(Sprite* sprite, double x, double y);
    void EndDraw();
    bool IsOpen() const;
    DrawDevice* GetDrawDevice();
    HWND GetWindow() const;
    static LRESULT CALLBACK msgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
    HWND mainWindow;
    HINSTANCE hInstance;
    int nCmdShow;
    DrawDevice* device;
    LPCWSTR lpWindowTitle;
    int width;
    int height;
    void Register(); // Registers the window class
    void Init(); // Saves instance handle and creates main window
};

typedef Window* LPWINDOW;