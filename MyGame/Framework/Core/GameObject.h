#pragma once 
#include <vector>
#include "../Utility/Vector2D.h"
#include "../Graphic/Animation.h"

using namespace std;
class GameObject
{
public:
	GameObject();
	~GameObject();
	void Update(double delta);
	void LateUpdate();
	void AddAnimation(Animation* animation);
	Animation*  GetAnimation(int index) const;
	Vector2D position;
	Vector2D velocity;
	Vector2D acceleration;
	

private:
	vector<Animation*> animations;
};