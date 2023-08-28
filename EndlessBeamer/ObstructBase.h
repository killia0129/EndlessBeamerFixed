#pragma once
#include "Object.h"

const int MaxColorValue = 255;

class ObstructBase :
    public Object
{
public:
    virtual void Update(float deltaTime)override = 0;//���t���[���Ăяo��
    virtual void Draw()override = 0;//�`��

protected:
    float hp;//HP
    float maxHp;
    unsigned int color;//�`��F
    int redColorValue;//�ԐF�̊���
    bool deadFlag;//��������ۂ�true
    void ColorCanger();
};

