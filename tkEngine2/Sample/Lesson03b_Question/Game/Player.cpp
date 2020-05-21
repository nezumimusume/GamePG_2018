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

	rotation.SetRotationDeg(g_vec3AxisY, 180.0f);

	skinModelRender->SetShadowReceiverFlag(true);
	skinModelRender->SetShadowCasterFlag(true);

	
	return true;
}
//キャラクターの移動処理。
void Player::Move()
{
	if (g_pad[0]->IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		position.x += 10.0f;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		position.x -= 10.0f;
	}
	if (g_pad[0]->IsPress(enButtonUp)) {
		position.z += 10.0f;
	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		position.z -= 10.0f;
	}
	if (g_pad[0]->IsTrigger(enButtonA)) {
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
		isJump = false;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}
//キャラクターの回転処理。
void Player::Rotation()
{
	// キャラクタを右に向かせる。
	if (g_pad[0]->IsPress(enButtonRight)) {
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * 0.5f);	//ラジアン単位の別解。
	}
	//キャラクタを左に向かせる。
	if (g_pad[0]->IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(g_vec3AxisY, -90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * -0.5f);	//ラジアン単位の別解。
	}
	//キャラクタを奥に向かせる。
	if (g_pad[0]->IsPress(enButtonUp)) {
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f);
		//rotation.SetRotation(CVector3::AxisY, 0.0f);		//ラジアン単位の別解。
	}
	//キャラクタを手前に向かせる。
	if (g_pad[0]->IsPress(enButtonDown)) {
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI);	//ラジアン単位の別解。
	}

	//モデルに回転を反映させる。
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	
	//////////////////////////////////////////////////////////////////////////
	//実習課題 1 左右のボタンでも走りアニメーションを再生できるようにしなさい。
	//////////////////////////////////////////////////////////////////////////
	
	//HandsOn 1 走りアニメーションを再生してみよう。	
	if (isJump == false) {
		if (g_pad[0]->IsPress(enButtonUp)) {
			//ゲームパッドの上ボタンが押されているなら。
			//走るアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		if (g_pad[0]->IsPress(enButtonDown)) {
			//ゲームパッドの下ボタンが押されているなら。
			//走るアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else {
			//何も入力されていなければ立ちアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
	}
	//HandsOn 2 ジャンプアニメーションを再生してみよう。
	if (g_pad[0]->IsTrigger(enButtonA)) {
		skinModelRender->PlayAnimation(enAnimationClip_jump);
		isJump = true;
	}
}
void Player::Update()
{
	Move();
	Rotation();
	AnimationControl();
}