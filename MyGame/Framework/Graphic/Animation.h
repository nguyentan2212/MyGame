#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Sprite.h"
#include <vector>

class Animation
{
public:
	Animation();
	bool UpdateFrame(double deltaTime);
	void AddSprite(Sprite* _sprite);
	Sprite* GetCurrentFrame() const;
	void Reset();

private:
	void IncrementFrame();

	// Stores all frames for our animation.
	std::vector<Sprite*> frames;

	// Current frame.
	int currentFrameIndex;

	// We use this to decide when to transition to the next frame.
	double currentFrameTime;
};