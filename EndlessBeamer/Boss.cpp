#include "Boss.h"

const float MainR = 14.f;
const float CoreR = 7.f;
const float DefaultHp = 2.f;
const float XSpeed = 0.3f;
const float YSpeed = 0.4f;
const float MaxRad = 2.f;
const float QuarterRad = 0.5f;
const float OneEighthRad = 0.25f;
const float MainToBitDis = 20.f;
const float MainToNeedleDis = 14.f;
const float MainToNeedleTopDis = 25.f;
const float TurnSpeed = 1.f;
const float StopUpPosZ = 200.f;
const float Speed = 15.f;
const float StageHalfWidth = StageWidth / 2.f;
const float BitSpeed[4] = { 1.5f,2.0f,1.f,2.5f };
const float BitR = 2.f;
const float NeedleR = 4.f;
const int MainAlpha = 64;
const int CoreAlpha = 128;
const int AlfaBlendDiff = 2;
const int DivNum = 16;

Boss::Boss(VECTOR _pos)
{
	deadFlag = false;
	pos = _pos;
	for (int i = 0; i < AfterImageNum; i++)
	{
		prevPos[i] = _pos;
	}
	hp = DefaultHp;
	xSpeed = XSpeed;
	ySpeed = YSpeed;
}

Boss::~Boss()
{
}

void Boss::Update(float deltaTime)
{
}

void Boss::Draw()
{
}


