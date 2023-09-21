#include "GameScene.h"

const float MsRatio = 1000.f;
const float BackEffectAddSec = 0.3f;
const int BeamStartNum = 10;
const int BeamAddNum = 20;
const float NearCameraEnd = 1.f;
const float FarCameraEnd = 499.f;
const VECTOR ZeroPos = VGet(0, 0, 0);
const VECTOR CameraVec = VGet(0, 0, 1);
const float MaxTime = 60.f;
const int CellSize = 4;
const int DefaultWindowWidth = 1920;
const int DefaultWindowHeight = 1080;
const int DownScaleScreenRatio = 2;
const float CellDefaultPosXY = -15.f;
const float CellDefaultPosZ = 500.f;
const float CellDiff = 10.f;
const int BackEffectAddNum = 50;
const int MaxObstructNum = 30;
const float ObsAddSec = 3.f;
const int ObsNormalTypeNum = 2;
const int WaveTypeNum = 2;
const int BeamNum = 4;
const float BeamCoolDown = 6.0;

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
	obj->SetPlayerAndPlayerBeam();
	backCool = 0.f;
	count = 0.f;
	obsCool = 0.f;
	beamCool = 0.f;
	deleteCount = 0;
	time = MaxTime;
	blinkRad = 0.f;
	seed = 0;
	phase = TUTORIAL;

	for (int i = 0; i < CellSize; i++)
	{
		for (int j = 0; j < CellSize; j++)
		{
			cell[i][j] = VGet(CellDefaultPosXY + CellDiff * (float)i, CellDefaultPosXY + CellDiff * (float)j, CellDefaultPosZ);
		}
	}

	for (int i = 0; i < BeamNum; i++)
	{
		Beam* newBeam = new Beam(i);
		beam[i] = newBeam;
	}

	colorScreen = MakeScreen(DefaultWindowWidth, DefaultWindowHeight, false);
	DownScaleScreen = MakeScreen(DefaultWindowWidth / DownScaleScreenRatio, DefaultWindowHeight / DownScaleScreenRatio, false);
	gaussScreen = MakeScreen(DefaultWindowWidth / DownScaleScreenRatio, DefaultWindowHeight / DownScaleScreenRatio, false);
}

GameScene::~GameScene()
{
}

void GameScene::Update()
{
	//Œo‰ßŽžŠÔ
	nowTime = (float)GetNowCount() / MsRatio;
	deltaTime = nowTime - prevTime;
	count += deltaTime;
	obsCool += deltaTime;
	backCool += deltaTime;
	time -= deltaTime;


	if (deleteCount >= BeamStartNum)
	{
		beamCool += deltaTime;
	}
	srand(seed);

	SetDrawScreen(colorScreen);
	ClearDrawScreen();
	SetCameraNearFar(NearCameraEnd, FarCameraEnd);
	SetCameraPositionAndTarget_UpVecY(ZeroPos, CameraVec);

	if (backCool >= BackEffectAddSec)
	{
		for (int i = 0; i < BackEffectAddNum; i++)
		{
			BackEffect* newObj = new BackEffect();
			obj->Entry(newObj);
		}
		backCool = 0.f;
	}

	switch (phase)
	{
	case TUTORIAL:
		break;

	case NORMAL:
		break;

	case BEAM_ONE:
		break;

	case BEAM_TWO:
		break;

	case CHANGE_BOSS:
		break;

	case BOSS:
		break;

	default:
		break;
	}

	


	

	prevTime = nowTime;
}

void GameScene::TutorialUpdate()
{
	if (obj->TypeObjetNumGetter(ObjectType::TUTORIAL) == 0)
	{
		phase = NORMAL;
	}
}

void GameScene::NormalUpdate()
{
	if (obsCool > ObsAddSec)
	{
		int type = rand() % ObsNormalTypeNum;
		int cellX, cellY;

		if (type == 0)
		{
			cellY = rand() % CellSize;
			int wave = rand() % WaveTypeNum;
			if (wave == 0)
			{
				cellX = rand() % (CellSize/2) + 1;
				Meteor* newObj = new Meteor(cell[cellX][cellY], true);
				obj->Entry(newObj);
			}
			else
			{
				cellX = rand() % CellSize;
				Meteor* newObj = new Meteor(cell[cellX][cellY], false);
				obj->Entry(newObj);
			}
		}
		else
		{
			cellX = rand() % CellSize;
			cellY = rand() % CellSize;
			Needle* newObj = new Needle(cell[cellX][cellY]);
			obj->Entry(newObj);
		}
		obsCool = 0.f;
	}
	deleteCount += obj->KilledNum();
	if (deleteCount >= BeamStartNum)
	{
		phase = BEAM_ONE;
	}
}

void GameScene::BeamOneUpdate()
{
	NormalUpdate();
	if (beamCool >= BeamCoolDown)
	{
		beam[rand() & BeamNum]->Start();
		beamCool = 0.f;
	}
	for (auto ptr : beam)
	{
		ptr->HitCheck(obj->PlayerPosGetter());
	}
	if (deleteCount >= BeamAddNum)
	{
		phase = BEAM_TWO;
	}
}

void GameScene::BeamTwoUpdate()
{
	NormalUpdate();
	if (beamCool >= BeamCoolDown)
	{
		int tmp1 = rand() % BeamNum;
		int tmp2;
		do
		{
			tmp2 = rand() % BeamNum;
		} while (tmp1 == tmp2);
		beam[tmp1]->Start();
		beam[tmp2]->Start();
	}
	for (auto ptr : beam)
	{
		ptr->HitCheck(obj->PlayerPosGetter());
	}
	if (deleteCount >= BeamAddNum)
	{
		phase = CHANGE_BOSS;
	}
}

void GameScene::ChangeBossUpdate()
{
}

void GameScene::BossUpdate()
{
}
