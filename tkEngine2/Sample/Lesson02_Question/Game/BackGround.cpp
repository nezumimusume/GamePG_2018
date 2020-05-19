#include "stdafx.h"
#include "BackGround.h"


BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

bool BackGround::Start()
{
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/backGround.cmo");
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetPosition({ 0.0f, 30.0f, 0.0f });
	return true;
}