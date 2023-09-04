#pragma once
#include "Object.h"
class Player :
    public Object
{
public:
    Player();
    virtual ~Player();
    void Update(float deltaTime)override;
    void Draw()override;
    VECTOR PosGetter();

private:
    VECTOR prevAheadPos[16];
    VECTOR prevBackPos[16];
    VECTOR aheadPos;
    VECTOR backPos;
    void SetCapsulePos();
};

