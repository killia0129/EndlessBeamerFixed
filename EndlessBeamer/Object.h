#pragma once
#include"game.h"
class Object
{
public:
	virtual void Update(float deltaTime) = 0;//���t���[���Ăяo��
	virtual void Draw() = 0;//�`��
	ObjectType TypeGetter();//�I�u�W�F�N�g�̎�ނ�Ԃ�
	bool IsEnd();
	VECTOR PosGetter();
	void GivenDmg(float dmg);

protected:
	VECTOR pos;//���W
	ObjectType type;//�I�u�W�F�N�g��
	bool deadFlag;//��������ۂ�true
	float hp;//HP
};

