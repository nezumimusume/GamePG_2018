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

	CVector3 cameraTarget;
	cameraTarget.x = pl->position.x;
	cameraTarget.y = pl->position.y + 100.0f;	//�v���C���[�̂�����Ə�ɂ���B
	cameraTarget.z = pl->position.z;

	MainCamera().SetTarget(cameraTarget);
	//���_�͒����_����x�����Ɂ{�S�O�O�A�y�����Ɂ]�U�O�O�̏ꏊ�ɂ���B
	CVector3 cameraPos;
	cameraPos = cameraTarget;
	cameraPos.y += 400.0f;
	cameraPos.z -= 600.0f;
	MainCamera().SetPosition(cameraPos);
	MainCamera().SetFar(30000.0f);
	//�J�����s����X�V����B
	MainCamera().Update();
}