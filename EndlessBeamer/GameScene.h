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
/// �Q�[���v���C�V�[���̊Ǘ�
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


    ObjectController* obj = new ObjectController();//�I�u�W�F�N�g�Q
    UI* ui = new UI();
    VECTOR cell[4][4];//Obstruct�̏o���ʒu
    Beam* beam[4];//���ז��r�[��
    float count;//�o�ߎ���
    float obsCool;//Obstruct�̔����̑ҋ@����
    float backCool;//�w�i�G�t�F�N�g�̔����̑ҋ@����
    float beamCool;//���ז��r�[���̔����̑ҋ@����
    int deleteCount;//�󂳂ꂽObstruct�̐�
    float time;//��������
    float blinkRad;//��ʑS�̂̓_�Ő���p���W�A���p
    PHASE phase;
    void TutorialUpdate();
    void NormalUpdate();
    void BeamOneUpdate();
    void BeamTwoUpdate();
    void ChangeBossUpdate();
    void BossUpdate();

};

