#include "PlayerBeam.h"

const float NearMarkRatio = 50.0f / 80.0f;
const float FarMarkRatio = 110.0f / 80.0f;
const float EndMarkRatio = 500.0f / 80.0f;
const int DefaultMousePointX = 1920 / 2;
const int DefaultMousePointY = 1080 / 2;
const VECTOR DefaultNearTrianglePos = VGet(0, 0, 80.f);
const VECTOR DefaultFarTrianglePos = VGet(0, 0, 140.f);
const VECTOR DefaultPlayerPos = VGet(0, 0, 30.f);
const VECTOR DefaultBeamEndPos = VGet(0, 0, 530.f);
const int AfterImageNum = 16;
const VECTOR DefaultposPos = VGet(0, 0, 110.f);
const unsigned int NormalColor = GetColor(0, 255, 0);
const int AimSpeed = 100.f;
const int MouseBuffer = 0;
const float MaxStickSize = 32768.f;
const float PlayerHalfSize = 3.f;
const float OneSixthRad = DX_PI_F / 3.f;
const float OneTirdRad = DX_PI_F * 2 / 3;
const int MaxAfterImageAlfa = 128;
const int AlfaBlendDiff = 8;
const float BeamR = 0.5f;
const int BeamDivNum = 4;
const unsigned int AfterImageBeamColor = GetColor(10, 10, 255);
const unsigned int BeamColor = GetColor(42, 255, 255);
const float posR = 1.f;
const int posDivNum = 16;
const float AimLineLength = 20.f;


PlayerBeam::PlayerBeam()
{
    SetMousePoint(DefaultMousePointX, DefaultMousePointY);
    nearTrianglePos = DefaultNearTrianglePos;
    farTrianglePos = DefaultFarTrianglePos;
	playerPos = DefaultPlayerPos;
	beamEndPos = DefaultBeamEndPos;
	for (int i = 0; i < AfterImageNum; i++)
	{
		prevPlayerPos[i] = playerPos;
		prevBeamEndPos[i] = beamEndPos;
	}
	mousePointX = 0;
	mousePointY = 0;
	pos = DefaultposPos;
}

PlayerBeam::~PlayerBeam()
{
}

void PlayerBeam::Update(float deltaTime)
{
	//残像制御
	for (int i = AfterImageNum - 1; i >= 1; i--)
	{
		prevPlayerPos[i] = prevPlayerPos[i - 1];
		prevBeamEndPos[i] = prevBeamEndPos[i - 1];
	}
	prevPlayerPos[0] = playerPos;
	prevBeamEndPos[0] = beamEndPos;

	//マウスの位置を取得しposを移動
	GetMousePoint(&mousePointX, &mousePointY);
	if (mousePointX > DefaultMousePointX + MouseBuffer)
	{
		pos.x += (mousePointX - DefaultMousePointX - MouseBuffer) * AimSpeed * deltaTime;
	}
	if (mousePointX < DefaultMousePointX - MouseBuffer)
	{
		pos.x += (mousePointX - DefaultMousePointX - MouseBuffer) * AimSpeed * deltaTime;
	}
	if (mousePointY > DefaultMousePointY + MouseBuffer)
	{
		pos.y -= (mousePointY - DefaultMousePointY - MouseBuffer) * AimSpeed * deltaTime;
	}
	if (mousePointY < DefaultMousePointY - MouseBuffer)
	{
		pos.y -= (mousePointY - DefaultMousePointY - MouseBuffer) * AimSpeed * deltaTime;
	}

	//PADの入力を取得しposを移動
	XINPUT_STATE padInput;
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &padInput);


	pos.x += AimSpeed * deltaTime * ((float)padInput.ThumbRX / MaxStickSize);
	pos.y += AimSpeed * deltaTime * ((float)padInput.ThumbRY / MaxStickSize);

	playerPos.z += PlayerHalfSize;


	//補助の三角形の制御
	nearTrianglePos.x = (pos.x - playerPos.x) * NearMarkRatio + playerPos.x;
	nearTrianglePos.y = (pos.y - playerPos.y) * NearMarkRatio + playerPos.y;
	farTrianglePos.x = (pos.x - playerPos.x) * FarMarkRatio + playerPos.x;
	farTrianglePos.y = (pos.y - playerPos.y) * FarMarkRatio + playerPos.y;

	//ビームの位置制御
	beamEndPos.x = (pos.x - playerPos.x) * EndMarkRatio + playerPos.x;
	beamEndPos.y = (pos.y - playerPos.y) * EndMarkRatio + playerPos.y;

	//マウスを画面の中心に
	SetMousePoint(DefaultMousePointX, DefaultMousePointY);
}

void PlayerBeam::Draw()
{
	//ここから20230905
}

void PlayerBeam::SetPlayerpos(VECTOR pPos)
{
    playerPos = pPos;
}
