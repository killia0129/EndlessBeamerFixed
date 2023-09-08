#pragma once
#include "Object.h"
class PlayerBeam :
    public Object
{
public:
    PlayerBeam();
    virtual ~PlayerBeam();
    void Update(float deltaTime)override;
    void Draw()override;
    void SetPlayerpos(VECTOR pPos);

private:
    VECTOR nearTrianglePos;
    VECTOR farTrianglePos;
    int mousePointX;
    int mousePointY;
    VECTOR playerPos;
    VECTOR beamEndPos;
    VECTOR prevPlayerPos[16];
    VECTOR prevBeamEndPos[16];

    void SetDrawTriangle(VECTOR _pos);
};

