#pragma once
#include "ObstructBase.h"
class Needle :
    public ObstructBase
{
public:
    Needle(VECTOR _pos);
    virtual ~Needle();
    void Update(float deltaTime)override;
    void Draw()override;
};

