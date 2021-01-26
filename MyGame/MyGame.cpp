// MyGame.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "MyGame.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    Game game(hInstance, nCmdShow);
    while (game.IsRunning())
    {
        game.Update();
        game.LateUpdate();
        game.Draw();
    }
}
