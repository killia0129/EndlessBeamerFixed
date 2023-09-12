#pragma once
#include "SceneBase.h"
#include"Meteor.h"
#include"Needle.h"
#include"Boss.h"
#include"Player.h"
#include"PlayerBeam.h"
#include"UI.h";
class GameScene :
    public SceneBase
{
public:
    GameScene();
    virtual ~GameScene();
    void Update()override;
};

