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
	CQuaternion qRot;
	qRot.SetRotationDeg(g_vec3AxisY, 180.0f);
	skinModelRender->SetRotation(qRot);
	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);
	skinModelRender->SetPosition(position);

	return true;
}

void Player::Update()
{
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
	


	//キャラクターのY座標が0より小さくなったら
	//キャラのY座標も0にする。
	if (position.y <= 0.0f) {
		position.y = 0.0f;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
	
}