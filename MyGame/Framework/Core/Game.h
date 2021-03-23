#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Window.h"
#include "Timer.h"
#include "Manager.h"
#include "../Graphic/Animation.h"
#include "GameObject.h"
#include "KeyInput.h"
#include "../Utility/Debug.h"

class Game
{
public:
    Game(HINSTANCE _hInstance, int _nCmdShow);
    virtual void Initialize() = 0;
    virtual void Update() = 0;
    virtual void LateUpdate() = 0;
    virtual void Draw() = 0;
    bool IsRunning() const;

protected:
    HINSTANCE hInstance;                    // handle to an instance of the application
    int nCmdShow;
    int fps;								// frames per second
    double mspf;							// milliseconds per frame
    double deltaTime;						// game update rate
    LPWINDOW window;                        // game window
    LPTIMER timer;                          // timer
    Manager* manager;
    KeyInput* input;
    
    vector<GameObject*> objects;
};