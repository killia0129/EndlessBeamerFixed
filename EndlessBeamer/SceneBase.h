#pragma once
#include"game.h"
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void Update() = 0;
	virtual bool IsEnd();
	virtual GameScene NextScene();

protected:
	bool sceneEndFlag;//���̃V�[�����I�������true
	GameScenes nextScene;//���̃V�[����

	float deltaTime;
	float nowTime;
	float prevTime;
};

