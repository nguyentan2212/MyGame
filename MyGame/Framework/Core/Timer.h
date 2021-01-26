#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Timer
{
public:
	Timer();
	double getTotalTime() const;
	double getDeltaTime() const;
	void Start();
	void Reset();
	void Tick();
	void Stop();

private:
	long long int startTime;
	long long int currentTime;
	long long int previousTime;
	double deltaTime;
	bool isStopped;
};
typedef Timer* LPTIMER;