#include "stdafx.h"
#include "Player.h"


void Player::Update()
{
	//Hands-On 2 プレイヤーを動かしてみよう
	position.x -= 1.0f;
	position.z += 1.0f;

	//座標を絵描きさんに教える。
	skinModelRender->SetPosition(position);
}
bool Player::Start()
{
	//スキンモデルレンダラーを作成。
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/unityChan.cmo");
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	return true;
}