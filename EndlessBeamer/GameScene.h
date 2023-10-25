#pragma once
#include "SceneBase.h"
#include "ObjectController.h"
#include"Meteor.h"
#include"Needle.h"
#include"Boss.h"
#include"Player.h"
#include"PlayerBeam.h"
#include"BackEffect.h"
#include"UI.h";
#include"Beam.h"

/// <summary>
/// ゲームプレイシーンの管理
/// </summary>
class GameScene :
    public SceneBase
{
public:
    GameScene();
    virtual ~GameScene();
    void Update()override;

private:
    enum PHASE
    {
        TUTORIAL,NORMAL,BEAM_ONE,BEAM_TWO,BOSS,CHANGE_BOSS
    };


    ObjectController* obj = new ObjectController();//オブジェクト群
    UI* ui = new UI();
    VECTOR cell[4][4];//Obstructの出現位置
    Beam* beam[4];//お邪魔ビーム
    float count;//経過時間
    float obsCool;//Obstructの発生の待機時間
    float backCool;//背景エフェクトの発生の待機時間
    float beamCool;//お邪魔ビームの発生の待機時間
    int deleteCount;//壊されたObstructの数
    float time;//制限時間
    float blinkRad;//画面全体の点滅制御用ラジアン角
    PHASE phase;
    void TutorialUpdate();
    void NormalUpdate();
    void BeamOneUpdate();
    void BeamTwoUpdate();
    void ChangeBossUpdate();
    void BossUpdate();

};

