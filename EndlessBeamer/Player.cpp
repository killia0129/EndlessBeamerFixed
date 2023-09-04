#include "Player.h"

const VECTOR DefaultPos = VGet(0.f, 0.f, 30.f);
const float PlayerHalfSize = 3.f;
const int AfterImageNum = 16;
const float MaxPadInput = 32768.f;
const float Speed = 50.f;
const float StageHalfSize = StageHalfSize / 2.f;
const float PlayerR = 1.5f;

Player::Player()
{
	pos = DefaultPos;
	SetCapsulePos();
	for (int i = 0; i < AfterImageNum; i++)
	{
		prevAheadPos[i] = aheadPos;
		prevBackPos[i] = backPos;
	}
}

Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	//残像を格納
	for (int i = AfterImageNum - 1; i >= 1; i--)
	{
		prevAheadPos[i] = prevAheadPos[i - 1];
		prevBackPos[i] = prevBackPos[i - 1];
	}
	prevAheadPos[0] = aheadPos;
	prevBackPos[0] = backPos;

	//PADの入力を取得
	XINPUT_STATE padInput;
	GetJoypadXInputState(DX_INPUT_PAD1, &padInput);

	//PADの入力から移動
	pos.x += Speed * deltaTime * ((float)padInput.ThumbLX / MaxPadInput);
	pos.y += Speed * deltaTime * ((float)padInput.ThumbLY / MaxPadInput);

	//キーボード入力から移動
	if (CheckHitKey(KEY_INPUT_W))
	{
		pos.y += Speed * deltaTime;
	}
	if (CheckHitKey(KEY_INPUT_A))
	{
		pos.x -= Speed * deltaTime;
	}
	if (CheckHitKey(KEY_INPUT_S))
	{
		pos.y -= Speed * deltaTime;
	}
	if (CheckHitKey(KEY_INPUT_D))
	{
		pos.x += Speed * deltaTime;
	}

	//ステージ外に出ないように
	if (pos.x < (StageHalfSize) * (-1) + PlayerR)
	{
		pos.x = (StageHalfSize) * (-1) + PlayerR;
	}
	if (pos.x > (StageHalfSize) - PlayerR)
	{
		pos.x = (StageHalfSize) - PlayerR;
	}
	if (pos.y < (StageHalfSize) * (-1) + PlayerR)
	{
		pos.y = (StageHalfSize) * (-1) + PlayerR;
	}
	if (pos.y > (StageHalfSize) - PlayerR)
	{
		pos.y = (StageHalfSize) - PlayerR;
	}

	SetCapsulePos();
}

void Player::Draw()
{
	//残像描画
	//ここから20230904
}

VECTOR Player::PosGetter()
{
	return pos;
}

void Player::SetCapsulePos()
{
	aheadPos = pos;
	backPos = pos;
	aheadPos.z += PlayerHalfSize;
	backPos.z -= PlayerHalfSize;
}

