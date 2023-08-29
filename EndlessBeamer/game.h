#pragma once
#include"DxLib.h"

//シーン名
enum GameScene
{
	TITLE,GAME,CLEAR,OVER
};

//オブジェクト名
enum ObjectType
{
	NEEDLE,METEOR,PLAYER,BACK_GROUND
};

const int MaxAlphaRatio = 255;
const float MaxRad = 2.f;
const float StageWidth = 40.f;