#pragma once
#include "tkEngine/character/tkCharacterController.h"

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Rotation();
	void AnimationControl();
	//ここからメンバ変数。
	enum {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。
	CAnimationClip animationClips[enAnimationClip_num];		//アニメーションクリップ。

	
	CVector3 position = CVector3::Zero;
	CQuaternion rotation = CQuaternion::Identity;
	//HandsOn 3 PlayerクラスにCCharacterControllerのインスタンスを保持させる。
	CCharacterController charaCon;

	CVector3 moveSpeed = CVector3::Zero;
};

