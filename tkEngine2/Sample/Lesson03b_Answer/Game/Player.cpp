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
	position.x = 0.0f;
	position.y = 0.0f;
	position.z = 0.0f;
	skinModelRender->SetPosition(position);
	rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(rotation);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);

	return true;
}

void Player::Move() {
	//キャラクターの移動処理。

	if (g_pad[0]->IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		position.x += 10.0f;                      //キーボードの６キー
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		position.x -= 10.0f;                      //キーボードの４キー
	}
	if (g_pad[0]->IsPress(enButtonUp)) {  //もしもゲームパッドの上ボタンが推されていたら。
		position.z += 10.0f;                    //キーボードの８キー
	}
	if (g_pad[0]->IsPress(enButtonDown)) {  //もしもゲームパッドの下ボタンが推されていたら。
		position.z -= 10.0f;                      //キーボードの２キー
	}

	//キャラクターを複製してみよう。
	if (g_pad[0]->IsTrigger(enButtonSelect)) {//もしもゲームパッドのSelectボタンが押されていたら。
		NewGO<Player>(0);                           //キーボードのスペースキー
	}

	//キャラクターをジャンプさせてみよう。
	if (g_pad[0]->IsPress(enButtonA)) {  //もしもゲームパッドのAボタンが推されていたら。
		position.y += 5.0f;                    //キーボードのJ キー
	}
	//重力の影響を与える。
	position.y -= 0.5f;


	//キャラクターのY座標が0より小さくなったら
	//ジャンプ力を0にして、キャラのY座標も0にする。
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}

void Player::Rotation()
{
	//パッドの入力でキャラクターの回転処理。

	//Question 5 キャラクターを右に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f); //キーボードの６キー
		//rotation.SetRotation(g_vec3AxisY, 0.5 * CMath::PI); //Tips
	}

	//実習課題１ キャラクターを左に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 270.0f); //キーボードの４キー
	}

	//実習課題２ キャラクターを奥に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonUp)) {  //もしもゲームパッドの上ボタンが推されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f); //キーボードの８キー
	}

	//実習課題３ キャラクターを手前に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonDown)) {  //もしもゲームパッドの下ボタンが推されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f); //キーボードの２キー
	}

	//回転を絵描きさんに教える。
	skinModelRender->SetRotation(rotation);
}


void Player::Update()
{
	//Move();
	//Rotation();
	



}