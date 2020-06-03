#pragma once
#include "tkEngine/character/tkCharacterController.h"

class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void MovePosition();
	void MoveSpeed();
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

	bool isJump = false;
	CVector3 position ;
	CQuaternion rotation ;
	CVector3 moveSpeed;

	//HandsOn3 CCharacterControllerクラスのオブジェクトをメインメモリに展開し保持させる。
	CCharacterController charaCon; //キャラクターコントローラー
	
};

