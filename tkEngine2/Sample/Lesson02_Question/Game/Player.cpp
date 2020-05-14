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
	position.x = 100.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetPosition(position);

	return true;
}

void Player::Update()
{
<<<<<<< HEAD
	//キャラクターの移動処理。

	//Question 1 キャラクターを左右に動かしてみよう。





	//Question 2 キャラクターを複製してみよう。
	



	//実習課題

	//「もしも、パッドの上ボタンが押されたら」というif文を追加する
	//パッドの上ボタンが押されたら、画面の奥に移動する




	//実習課題
	//「もしも、パッドの下ボタンが押されたら」というif文を追加する
	//パッドの下ボタンが押されたら、画面の手前に移動する




	//Question 3 キャラクターをジャンプさせてみよう。


	

	//Question 4 重力の影響を与える。
	


=======
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
	if (Pad(0).IsPress(enButtonA)) {
		position.y += 5.0f;
	}

	//重力の影響を与える。
	position.y -= 0.5f;

	//Y方向の速度を座標に加算する。
>>>>>>> b0a2522240711ef38451584b35669d5750297270
	//キャラクターのY座標が0より小さくなったら
	//キャラのY座標も0にする。
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
	
}