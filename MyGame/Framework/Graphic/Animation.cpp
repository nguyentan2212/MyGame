#include "Animation.h"

Animation::Animation() :currentFrameIndex(0),currentFrameTime(0), frames(0)
{
}

bool Animation::UpdateFrame(double deltaTime)
{
    if (frames.size() > 0)
    {
        currentFrameTime += deltaTime;

        if (currentFrameTime >= frames[currentFrameIndex]->GetTime())
        {
            currentFrameTime = 0.f;
            IncrementFrame();
            return true;
        }
    }

    return false;
}

void Animation::AddSprite(Sprite* _sprite)
{
    frames.push_back(_sprite);
}

Sprite* Animation::GetCurrentFrame() const
{
	if (frames.size() > 0)
	{
		return frames[currentFrameIndex];
	}
	return nullptr;
}

void Animation::Reset()
{
    currentFrameIndex = 0;
    currentFrameTime = 0;
}

void Animation::IncrementFrame()
{
    currentFrameIndex = (currentFrameIndex + 1) % frames.size();
}
