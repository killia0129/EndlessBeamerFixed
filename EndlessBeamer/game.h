#pragma once
#include"DxLib.h"

//�V�[����
enum GameScene
{
	TITLE,GAME,CLEAR,OVER
};

//�I�u�W�F�N�g��
enum ObjectType
{
	NEEDLE,METEOR,PLAYER,BACK_GROUND
};

const int MaxAlphaRatio = 255;
const float MaxRad = 2.f;
const float StageWidth = 40.f;