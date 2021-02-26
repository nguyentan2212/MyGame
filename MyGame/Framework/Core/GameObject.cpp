#include "GameObject.h"

GameObject::GameObject()
{
	position = Vector2D::Zero();
	velocity = Vector2D::Zero();
	acceleration = Vector2D::Zero();
}

GameObject::~GameObject()
{
}

void GameObject::Update(double delta)
{
	velocity = velocity + acceleration * delta * delta / 2.0;
	position = position + velocity * delta;
	animations[0]->UpdateFrame(delta);
}

void GameObject::LateUpdate()
{
}

void GameObject::AddAnimation(Animation* animation)
{
	animations.push_back(animation);
}

Animation* GameObject::GetAnimation(int index) const
{
	if (index < 0 || index >= animations.size())
	{
		return nullptr;
	}
	return animations[index];
}
