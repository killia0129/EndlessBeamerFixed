#pragma once
#include"game.h"
class Object
{
public:
	virtual void Update(float deltaTime) = 0;
	virtual void Draw() = 0;
	ObjectType TypeGetter();

protected:
	VECTOR pos;
	ObjectType type;
};

