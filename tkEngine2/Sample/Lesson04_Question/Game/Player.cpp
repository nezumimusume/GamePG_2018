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

	rotation.SetRotationDeg(CVector3::AxisY, 180.0f);

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
		isJump = false;
	}
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}
//キャラクターの回転処理。
void Player::Rotation()
{
	//Question 1 キャラクタを右に向かせてみよう。
	if (Pad(0).IsPress(enButtonRight)) {
		rotation.SetRotationDeg(CVector3::AxisY, 90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * 0.5f);	//ラジアン単位の別解。
	}
	//実習課題 1 キャラクタを左に向かせてみよう。
	if (Pad(0).IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(CVector3::AxisY, -90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * -0.5f);	//ラジアン単位の別解。
	}
	//実習課題 2 キャラクタを奥に向かせてみよう。
	if (Pad(0).IsPress(enButtonUp)) {
		rotation.SetRotationDeg(CVector3::AxisY, 0.0f);
		//rotation.SetRotation(CVector3::AxisY, 0.0f);		//ラジアン単位の別解。
	}
	//実習課題 3 キャラクタを手前に向かせてみよう。
	if (Pad(0).IsPress(enButtonDown)) {
		rotation.SetRotationDeg(CVector3::AxisY, 180.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI);	//ラジアン単位の別解。
	}

	//モデルに回転を反映させる。
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	if (isJump == false) {
		//////////////////////////////////////////////////////////////////////////
		//実習課題 1 左右のボタンでも走りアニメーションを再生できるようにしなさい。
		//////////////////////////////////////////////////////////////////////////
		//HandsOn 1 走りアニメーションを再生してみよう。
		if (Pad(0).IsPress(enButtonUp)) {
			//ゲームパッドの上ボタンが押されているなら。
			//走るアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (Pad(0).IsPress(enButtonDown)) {
			//ゲームパッドの下ボタンが押されているなら。
			//走るアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (Pad(0).IsPress(enButtonRight)) {
			//ゲームパッドの右ボタンが押されているなら。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (Pad(0).IsPress(enButtonLeft)) {
			//ゲームパッドの左ボタンが押されているなら。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else {
			//何も入力されていなければ立ちアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
	}
	//ジャンプ中でなければ。
	//HandsOn 2 ジャンプアニメーションを再生してみよう。
	if (Pad(0).IsTrigger(enButtonA)) {
		skinModelRender->PlayAnimation(enAnimationClip_jump);
		isJump = true;	//ジャンプ中のフラグを立てる。
	}
}
void Player::Update()
{
	Move();
	Rotation();
	AnimationControl();
}