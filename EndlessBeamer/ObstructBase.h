#pragma once
#include "Object.h"
class ObstructBase :
    public Object
{
public:
    virtual void Update(float deltaTime)override = 0;
    virtual void Draw()override = 0;

protected:
    float hp;
    unsigned int color;
    int redColorValue;
};

