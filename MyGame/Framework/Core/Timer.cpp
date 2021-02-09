#include "Timer.h"

Timer::Timer()
{
	startTime = 0;
	currentTime = 0;
	previousTime = 0;
	deltaTime = 0;
	isStopped = true;
}

double Timer::getTotalTime() const
{
	return (currentTime - startTime);
}

double Timer::getDeltaTime() const
{
	return deltaTime;
}

void Timer::Start()
{
	if (isStopped)
	{
		startTime = GetTickCount64();
		previousTime = startTime;
		isStopped = false;
		//log
		return;
	}
	else
	{
		// log
		return;
	}
}

void Timer::Reset()
{
	startTime = GetTickCount64();
	previousTime = startTime;
	isStopped = false;
	// log
}

void Timer::Tick()
{
	if (isStopped)
	{
		deltaTime = 0;
		// log
		return;
	}
	else
	{
		currentTime = GetTickCount64();
		deltaTime = (currentTime - previousTime);
		previousTime = currentTime;
		if (deltaTime < 0.0)
			deltaTime = 0.0;
		// log
		return;
	}
}

void Timer::Stop()
{
	if (!isStopped)
	{
		isStopped = true;
		// log
		return;
	}
	else
	{
		// log
		return;
	}
}
