#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"

GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

void GameCamera::Update()
{
	//�v���C���[�̃C���X�^���X�𖼑O�Ō�������B
	Player* pl = FindGO<Player>("UnityChan");
	//HandsOn 1 �����_�𓮂����B
	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;	//�v���C���[�̂�����Ə�ɂ���B
	cameraTarget.z = pl->position.z;

	//�����_���J�����ɓ`����B
	MainCamera().SetTarget(cameraTarget);

	//HandsOn 2 ���_�𓮂����B
	//���_�͒����_����x�����Ɂ{�S�O�O�A�y�����Ɂ]�U�O�O�̏ꏊ�ɂ���B
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z -= 600.0f;

	//���_���J�����ɓ`����B
	MainCamera().SetPosition(cameraPos);

	//HandsOn 3 �����ʂ�ݒ肷��B
	MainCamera().SetFar(30000.0f);

	//HandsOn 4 ��p��ύX���Ă݂�B
	//��p��120�x�ɂ��Ă݂�B
	MainCamera().SetViewAngle(CMath::DegToRad(120.0f));

	//�J�����s����X�V����B
	MainCamera().Update();
}