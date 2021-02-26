#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <dinput.h>
#define KEYBOARD_BUFFER_SIZE 256
class KeyInput
{
public:
	KeyInput(HINSTANCE hInstance, HWND hWnd);
	void CaptureInput();
	bool IsKeyPress(int keyCode);
	bool IsKeyDown(int keyCode);
	bool IsKeyUp(int keyCode);

private:
	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data
	bool lastFrameKeys[KEYBOARD_BUFFER_SIZE];
	bool thisFrameKeys[KEYBOARD_BUFFER_SIZE];
};