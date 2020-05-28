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

	//HandsOn 4 CCharacterControllerのインスタンスを初期化する。
	charaCon.Init(
		20.0f,		//キャラクターの半径。
		68.0f,		//キャラクターの高さ。
		position	//キャラクターの初期座標。
	);
	
	return true;
}
//キャラクターの移動処理。
void Player::Move()
{
	float fSpeed = 20.0f;
	moveSpeed.x = 0.0f;
	moveSpeed.z = 0.0f;
	
	/////////////////////////////////////////////////////////////////////////////////
	//　実習課題 1 Bボタンを押しながら移動すると、移動速度が２倍になるようにしなさい。
	/////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////
	//　実習課題 2 Yボタンを押しながら移動すると、移動速度が半分になるようにしなさい。
	/////////////////////////////////////////////////////////////////////////////////
	if (g_pad[0]->IsPress(enButtonB)) {
		fSpeed *= 2.0f;
	}
	if (g_pad[0]->IsPress(enButtonRight)) { //もしもゲームパッドの右ボタンが押されていたら。
		moveSpeed.x = fSpeed;
	}
	if (g_pad[0]->IsPress(enButtonLeft)) {  //もしもゲームパッドの左ボタンが推されていたら。
		moveSpeed.x -= fSpeed;
	}
	if (g_pad[0]->IsPress(enButtonUp)) {
		moveSpeed.z = fSpeed;
	}
	if (g_pad[0]->IsPress(enButtonDown)) {
		moveSpeed.z = -fSpeed;
	}
	if (g_pad[0]->IsTrigger(enButtonA)) {
		//ジャンプする。
		moveSpeed.y = 40.0f;
	}

	//重力の影響を与える。
	moveSpeed.y -= 2.0f;

	//移動はキャラクターコントローラーに移動速度を与えて行う。
	//プレイヤーはキャラクタコントローラーによる移動結果を得るのみ。
	//HandsOn 5 CCharacterControllerを使って、キャラクターを移動させる。
	position = charaCon.Execute(1.0f, moveSpeed);
	
	//モデルに座標を反映させる。
	skinModelRender->SetPosition(position);
}
//キャラクターの回転処理。
void Player::Rotation()
{
	
	if (g_pad[0]->IsPress(enButtonRight)) {
		rotation.SetRotationDeg(g_vec3AxisY, 90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * 0.5f);	//ラジアン単位の別解。
	}
	
	if (g_pad[0]->IsPress(enButtonLeft)) {
		rotation.SetRotationDeg(g_vec3AxisY, -90.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI * -0.5f);	//ラジアン単位の別解。
	}
	
	if (g_pad[0]->IsPress(enButtonUp)) {
		rotation.SetRotationDeg(g_vec3AxisY, 0.0f);
		//rotation.SetRotation(CVector3::AxisY, 0.0f);		//ラジアン単位の別解。
	}
	
	if (g_pad[0]->IsPress(enButtonDown)) {
		rotation.SetRotationDeg(g_vec3AxisY, 180.0f);
		//rotation.SetRotation(CVector3::AxisY, CMath::PI);	//ラジアン単位の別解。
	}

	//モデルに回転を反映させる。
	skinModelRender->SetRotation(rotation);

}
void Player::AnimationControl()
{
	if (charaCon.IsJump() == false) {
		
		//HandsOn 1 走りアニメーションを再生してみよう。
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
	Move();
	Rotation();
	AnimationControl();
}