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
//キャラクターの移動処理。
void Player::Move()
{
	if (Pad(0).IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		position.x += 10.0f;
	}
	if (Pad(0).IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		position.x -= 10.0f;
	}
	if (Pad(0).IsPress(enButtonUp)) {
		position.z += 10.0f;
	}
	if (Pad(0).IsPress(enButtonDown)) {
		position.z -= 10.0f;
	}
	if (Pad(0).IsTrigger(enButtonA)) {
		ySpeed = 20.0f; //ｙ方向の速度を設定する。
	}

	//重力の影響を与える。
	ySpeed -= 1.0f;

	//Y方向の速度を座標に加算する。
	position.y += ySpeed;
	//キャラクターのY座標が0より小さくなったら
	//ジャンプ力を0にして、キャラのY座標も0にする。
	if (position.y <= 0.0f) {
		ySpeed = 0.0f;
		position.y = 0.0f;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}
//キャラクターの回転処理。
void Player::Rotation()
{
	//Question 1 キャラクタを右に向かせてみよう。
	
	//実習課題 1 キャラクタを左に向かせてみよう。
	
	//実習課題 2 キャラクタを奥に向かせてみよう。
	
	//実習課題 3 キャラクタを手前に向かせてみよう。
	

	//モデルに回転を反映させる。
	skinModelRender->SetRotation(rotation);


}
void Player::Update()
{
	Move();
	Rotation();
}