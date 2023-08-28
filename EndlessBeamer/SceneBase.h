#pragma once
#include"game.h"
class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	virtual void Update(float deltaTime) = 0;
	virtual bool IsEnd();
	virtual GameScene NextScene();

protected:
	bool sceneEndFlag;
	GameScene nextScene;
};

