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
	//アニメーションクリップをロード。
	animationClips[enAnimationClip_run].Load(L"animData/run.tka");
	animationClips[enAnimationClip_run].SetLoopFlag(true);	//ループモーションにする。
	animationClips[enAnimationClip_idle].Load(L"animData/idle.tka");
	animationClips[enAnimationClip_idle].SetLoopFlag(true);	//ループモーションにする。
	animationClips[enAnimationClip_jump].Load(L"animData/jump.tka");

	//スキンモデルレンダラーを作成。
	skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	skinModelRender->Init(L"modelData/unityChan.cmo", animationClips, enAnimationClip_num, CSkinModel::enFbxUpAxisY);
	
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
		isJump = false;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}

void Player::Rotation()
{
	//パッドの入力でキャラクターの回転処理。

	//キャラクターを右に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f); //キーボードの６キー
		//rotation.SetRotation(g_vec3AxisY, 0.5 * CMath::PI); //Tips
	}

	//キャラクターを左に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 270.0f); //キーボードの４キー
	}

	//キャラクターを奥に向かせてみよう。
	if (g_pad[0]->IsPress(enButtonUp)) {  //もしもゲームパッドの上ボタンが推されていたら。
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f); //キーボードの８キー
	}

	//キャラクターを手前に向かせてみよう。
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
	
	//if (isJump == false) {
	//	//////////////////////////////////////////////////////////////////////////
	//	//実習課題 1 左右のボタンでも走りアニメーションを再生できるようにしなさい。
	//	//////////////////////////////////////////////////////////////////////////
	//	//HandsOn 1 走りアニメーションを再生してみよう。
	//	if (g_pad[0]->IsPress(enButtonUp)) {
	//		//ゲームパッドの上ボタンが押されているなら。
	//		//走るアニメーションを再生する。
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else if (g_pad[0]->IsPress(enButtonDown)) {
	//		//ゲームパッドの下ボタンが押されているなら。
	//		//走るアニメーションを再生する。
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else if (g_pad[0]->IsPress(enButtonRight)) {
	//		//ゲームパッドの右ボタンが押されているなら。
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else if (g_pad[0]->IsPress(enButtonLeft)) {
	//		//ゲームパッドの左ボタンが押されているなら。
	//		skinModelRender->PlayAnimation(enAnimationClip_run);
	//	}
	//	else {
	//		//何も入力されていなければ立ちアニメーションを再生する。
	//		skinModelRender->PlayAnimation(enAnimationClip_idle);
	//	}
	//}
	////ジャンプ中でなければ。
	////HandsOn 2 ジャンプアニメーションを再生してみよう。
	//if (g_pad[0]->IsTrigger(enButtonA)) {
	//	skinModelRender->PlayAnimation(enAnimationClip_jump);
	//	isJump = true;	//ジャンプ中のフラグを立てる。
	//}




}