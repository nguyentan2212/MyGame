#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Window.h"
#include "Timer.h"
#include "Manager/TextureManager.h"
#include "./Manager/GameManager.h"
#include "../Graphic/Animation.h"
#include "GameObject.h"
#include "KeyInput.h"
#include "../Utility/Debug.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>

class Game
{
public:
    Game(HINSTANCE _hInstance, int _nCmdShow);
    virtual void Update();
    virtual void LateUpdate();
    virtual void Draw();
    bool IsRunning() const;

protected:
    HINSTANCE hInstance;                    // handle to an instance of the application
    int nCmdShow;
    int fps;								// frames per second
    double mspf;							// milliseconds per frame
    double deltaTime;						// game update rate
    LPWINDOW window;                        // game window
    LPTIMER timer;                          // timer
    GameManager* manager;
    TextureManager* textureManager;
    Animation* animation;
    KeyInput* input;
    GameObject* object;
};