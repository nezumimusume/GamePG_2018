#include "stdafx.h"
#include "Player.h"


Player::Player()
{
}


Player::~Player()
{
	DeleteGO(skinModelRender);
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

	position = { -300.0f,1000.0f,0.0f }; //以下と同じこと
	//position.x = -300.0f;
	//position.y = 1000.0f;
	//position.z = 0.0f;

	charaCon.Init(
		20.0f,		//キャラクターの半径。
		75.0f,		//キャラクターの高さ。
		position	//キャラクターの初期座標。
	);
	
	return true;
}
//キャラクターの移動処理。 速度
void Player::MoveSpeed()
{
	float fSpeed = 20.0f;
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	

	if (g_pad[0]->IsPress(enButtonB)) { //もしもゲームパッドのBボタンが押されていたら。
		fSpeed *= 2.0f;
	}
	if (g_pad[0]->IsPress(enButtonY)) { //もしもゲームパッドのYボタンが押されていたら。
		fSpeed /= 2.0f;
	}
	if (g_pad[0]->IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		moveSpeed.x = fSpeed;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		moveSpeed.x -= fSpeed;
	}
	if (g_pad[0]->IsPress(enButtonUp)) { //もしもゲームパッドの上ボタンが押されていたら。
		moveSpeed.z = fSpeed;
	}
	if (g_pad[0]->IsPress(enButtonDown)) { //もしもゲームパッドの下ボタンが押されていたら。
		moveSpeed.z = -fSpeed;
	}
	if (g_pad[0]->IsTrigger(enButtonA)) { //もしもゲームパッドのAボタンが押されていたら。
		//ジャンプする。
		//実習課題　ジャンプ音を再生する。
		prefab::CSoundSource* ss = NewGO<prefab::CSoundSource>(0);
		ss->Init("sound/jump.wav");
		ss->Play(false);

		moveSpeed.y = 40.0f;
	}

	//重力の影響を与える。
	moveSpeed.y -= 2.0f;

	//移動はキャラクターコントローラーに移動速度を与えて行う。
	//プレイヤーはキャラクタコントローラーによる移動結果を得るのみ。
	position = charaCon.Execute(1.0f, moveSpeed);
	
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}
//キャラクターの回転処理。
void Player::Rotation()
{
	
	if (g_pad[0]->IsPress(enButtonRight)) {
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f);
	}
	
	if (g_pad[0]->IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(g_vec3AxisY, -90.0f);
	}
	
	if (g_pad[0]->IsPress(enButtonUp)) {
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f);
	}
	
	if (g_pad[0]->IsPress(enButtonDown)) {
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
	}

	//モデルに回転を反映させる。
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	if (charaCon.IsJump() == false) {
		if (g_pad[0]->IsPress(enButtonUp)) {
			//ゲームパッドの上ボタンが押されているなら。
			//走るアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (g_pad[0]->IsPress(enButtonDown)) {
			//ゲームパッドの下ボタンが押されているなら。
			//走るアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (g_pad[0]->IsPress(enButtonRight)) {
			//ゲームパッドの右ボタンが押されているなら。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else if (g_pad[0]->IsPress(enButtonLeft)) {
			//ゲームパッドの左ボタンが押されているなら。
			skinModelRender->PlayAnimation(enAnimationClip_run);
		}
		else {
			//何も入力されていなければ立ちアニメーションを再生する。
			skinModelRender->PlayAnimation(enAnimationClip_idle);
		}
	}
	//ジャンプ中でなければ。
	if (g_pad[0]->IsTrigger(enButtonA)) {
		skinModelRender->PlayAnimation(enAnimationClip_jump);
	}
}
void Player::Update()
{
	MoveSpeed();
	Rotation();
	AnimationControl();
}