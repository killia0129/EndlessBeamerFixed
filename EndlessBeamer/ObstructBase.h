#pragma once
#include "Object.h"

const int MaxColorValue = 255;

class ObstructBase :
    public Object
{
public:
    virtual void Update(float deltaTime)override = 0;//毎フレーム呼び出す
    virtual void Draw()override = 0;//描画

protected:
    float hp;//HP
    float maxHp;
    unsigned int color;//描画色
    int redColorValue;//赤色の割合
    bool deadFlag;//消去する際にtrue
    void ColorCanger();
};

