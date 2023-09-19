#include "GameScene.h"

const float MsRatio = 1000.f;

GameScene::GameScene()
{
	sceneEndFlag = false;
	nextScene = CLEAR;
	deltaTime = 0.f;
	nowTime = (float)GetNowCount() / MsRatio;
	prevTime = nowTime;
	Object* newObj = new Player();
	obj->Entry(newObj);
	newObj = new PlayerBeam();
	obj->Entry(newObj);
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
}
