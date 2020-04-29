#include "stdafx.h"
#include "Player.h"


void Player::Update()
{
	//Hands-On 2 プレイヤーを動かしてみよう

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