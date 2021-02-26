#include "KeyInput.h"

KeyInput::KeyInput(HINSTANCE hInstance, HWND hWnd)
{
	HRESULT hr = DirectInput8Create(
		hInstance,
		DIRECTINPUT_VERSION,
		IID_IDirectInput8,
		(VOID**)&di,
		NULL);

	if (hr != DI_OK)
	{
		
		return;
	}
	
	hr = di->CreateDevice(GUID_SysKeyboard, &didv, NULL);

	// TO-DO: put in exception handling
	if (hr != DI_OK)
	{
		
		return;
	}

	hr = didv->SetDataFormat(&c_dfDIKeyboard);

	hr = didv->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);

	DIPROPDWORD dipdw;

	dipdw.diph.dwSize = sizeof(DIPROPDWORD);
	dipdw.diph.dwHeaderSize = sizeof(DIPROPHEADER);
	dipdw.diph.dwObj = 0;
	dipdw.diph.dwHow = DIPH_DEVICE;
	dipdw.dwData = KEYBOARD_BUFFER_SIZE; // Arbitary buffer size

	hr = didv->SetProperty(DIPROP_BUFFERSIZE, &dipdw.diph);

	hr = didv->Acquire();
	if (hr != DI_OK)
	{
		
		return;
	}
	
}

void KeyInput::CaptureInput()
{
	HRESULT hr;

	// Collect all key states first
	hr = didv->GetDeviceState(sizeof(keyStates), keyStates);
	if (FAILED(hr))
	{
		// If the keyboard lost focus or was not acquired then try to get control back.
		if ((hr == DIERR_INPUTLOST) || (hr == DIERR_NOTACQUIRED))
		{
			HRESULT h = didv->Acquire();
			if (h == DI_OK)
			{
			}
			else return;
		}
		else
		{
			//DebugOut(L"[ERROR] DINPUT::GetDeviceState failed. Error: %d\n", hr);
			return;
		}
	}


	// Collect all buffered events
	DWORD dwElements = KEYBOARD_BUFFER_SIZE;
	hr = didv->GetDeviceData(sizeof(DIDEVICEOBJECTDATA), keyEvents, &dwElements, 0);
	if (FAILED(hr))
	{
		return;
	}
	for (int i = 0; i < KEYBOARD_BUFFER_SIZE; i++)
	{
		lastFrameKeys[i] = thisFrameKeys[i];
	}
	for (int i = 0; i < dwElements; i++)
	{
		int keyCode = keyEvents[i].dwOfs;
		int keyState = keyEvents[i].dwData;
		thisFrameKeys[keyCode] = ((keyState & 0x80) > 0);
	}
}

bool KeyInput::IsKeyPress(int keyCode)
{
	return thisFrameKeys[keyCode];
}

bool KeyInput::IsKeyDown(int keyCode)
{
	return !lastFrameKeys[keyCode] && thisFrameKeys[keyCode];
}

bool KeyInput::IsKeyUp(int keyCode)
{
	return lastFrameKeys[keyCode] && !thisFrameKeys[keyCode];
}
