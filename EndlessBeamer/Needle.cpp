#include "Needle.h"

const int MaxColorValue = 255;
const float DefaultHP = 0.25f;

Needle::Needle(VECTOR _pos)
{
	pos = pos;
	color = GetColor(0, MaxColorValue, 0);
	type = NEEDLE;
	hp = DefaultHP;
}

Needle::~Needle()
{
}

void Needle::Update(float deltaTime)
{
}

void Needle::Draw()
{
}
