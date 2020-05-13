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
	skinModelRender->SetPosition(position);
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	return true;
}



void Player::Update()
{
	//キャラクターの移動処理。

	//Question 1 キャラを左右に動かしてみよう。
	if (Pad(0).IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		position.x += 10.0f;//キーボードの６キー
	}
	if (Pad(0).IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		position.x -= 10.0f; //キーボードの４キー
	}

	//Question 2 キャラクターを複製してみよう。
	if (Pad(0).IsPress(enButtonSelect)) {//もしもゲームパッドのSelectボタンが押されていたら。
		NewGO<Player>(0); //キーボードのスペースキー
	}

	//実習課題

	//「もしも、パッドの上ボタンが押されたら」というif文を追加する
	//パッドの上ボタンが押されたら、画面の奥に移動する
	if (Pad(0).IsPress(enButtonUp)) {
		position.z += 10.0f;
	}

	//実習課題
	//「もしも、パッドの下ボタンが押されたら」というif文を追加する
	//パッドの下ボタンが押されたら、画面の手前に移動する
	if (Pad(0).IsPress(enButtonDown)) {
		position.z -= 10.0f;
	}

	//Question 3 キャラクターをジャンプさせてみよう。
	if (Pad(0).IsPress(enButtonA)) {  //もしもゲームパッドのAボタンが推されていたら。
		position.y += 5.0f; //キーボードのJ キー
	}


	//Question 4 重力の影響を与える。
	position.y -= 0.5f;


	//キャラクターのY座標が0より小さくなったら
	//ジャンプ力を0にして、キャラのY座標も0にする。
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}