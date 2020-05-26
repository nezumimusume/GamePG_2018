#pragma once
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update();
	void Move();
	void Rotation();

	//ここからメンバ変数。
	prefab::CSkinModelRender* skinModelRender = nullptr;	//スキンモデルレンダラー。
	CVector3 position ;
	CQuaternion rotation ;
	enum {
		enAnimationClip_idle,
		enAnimationClip_run,
		enAnimationClip_jump,
		enAnimationClip_num,
	};
	CAnimationClip animationClips[enAnimationClip_num];		//アニメーションクリップ。
	bool isJump = false;

};

