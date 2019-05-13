#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
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
void Player::Update()
{
	//Question 1 キャラを左右に動かしてみよう。
	
	
	//実習課題 1  キャラを前後に動かしてみよう。
	
	
	//Question 3 キャラクタをジャンプさせてみよう。
	
	
	//Question 4 重力の影響を与えてみよう。
	
	
	//Y方向の速度を座標に加算する。
	position.y += ySpeed;
	//キャラクターのY座標が0より小さくなったら
	//ジャンプ力を0にして、キャラのY座標も0にする。
	if (position.y <= 0.0f) {
		ySpeed = 0.0f;
		position.y = 0.0f;
	}
	
	skinModelRender->SetPosition(position);
}